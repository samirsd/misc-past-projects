using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;


namespace MvcVideoStoreProject.Models
{
    public partial class ShoppingWishList
    {
        VideoStoreEntities storeDB = new VideoStoreEntities();
        string ShoppingWishListId { get; set; }
        public const string WishListSessionKey = "WishListId";
        public static ShoppingWishList GetWishList(HttpContextBase context)
        {
            var wishlist = new ShoppingWishList();
            wishlist.ShoppingWishListId = wishlist.GetWishListId(context);
            return wishlist;
        }
        // Helper method to simplify shopping wishlist calls
        public static ShoppingWishList GetWishList(Controller controller)
        {
            return GetWishList(controller.HttpContext);
        }
        public void AddToWishList(Product album)
        {
            // Get the matching wishlist and album instances
            var wishlistItem = storeDB.WishLists.SingleOrDefault(
                c => c.WishListId == ShoppingWishListId
                && c.ProductId == album.ProductId);

            if (wishlistItem == null)
            {
                // Create a new wishlist item if no wishlist item exists
                wishlistItem = new WishList
                {
                    ProductId = album.ProductId,
                    WishListId = ShoppingWishListId,
                    Count = 1,
                    DateCreated = DateTime.Now
                };
                storeDB.WishLists.Add(wishlistItem);
            }
            else
            {
                // If the item does exist in the wishlist, 
                // then add one to the quantity
                wishlistItem.Count++;
            }
            // Save changes
            storeDB.SaveChanges();
        }
        public int RemoveFromWishList(int id)
        {
            // Get the wishlist
            var wishlistItem = storeDB.WishLists.Single(
                wishlist => wishlist.WishListId == ShoppingWishListId
                && wishlist.RecordId == id);

            int itemCount = 0;

            if (wishlistItem != null)
            {
                if (wishlistItem.Count > 1)
                {
                    wishlistItem.Count--;
                    itemCount = wishlistItem.Count;
                }
                else
                {
                    storeDB.WishLists.Remove(wishlistItem);
                }
                // Save changes
                storeDB.SaveChanges();
            }
            return itemCount;
        }
        public void EmptyWishList()
        {
            var wishlistItems = storeDB.WishLists.Where(
                wishlist => wishlist.WishListId == ShoppingWishListId);

            foreach (var wishlistItem in wishlistItems)
            {
                storeDB.WishLists.Remove(wishlistItem);
            }
            // Save changes
            storeDB.SaveChanges();
        }
        public List<WishList> GetWishListItems()
        {
            return storeDB.WishLists.Where(
                wishlist => wishlist.WishListId == ShoppingWishListId).ToList();
        }
        public int GetCount()
        {
            // Get the count of each item in the wishlist and sum them up
            int? count = (from wishlistItems in storeDB.WishLists
                          where wishlistItems.WishListId == ShoppingWishListId
                          select (int?)wishlistItems.Count).Sum();
            // Return 0 if all entries are null
            return count ?? 0;
        }
        public decimal GetTotal()
        {
            // Multiply album price by count of that album to get 
            // the current price for each of those albums in the wishlist
            // sum all album price totals to get the wishlist total
            decimal? total = (from wishlistItems in storeDB.WishLists
                              where wishlistItems.WishListId == ShoppingWishListId
                              select (int?)wishlistItems.Count *
                              wishlistItems.Product.Price).Sum();

            return total ?? decimal.Zero;
        }
        public int CreateOrder(Order order)
        {
            decimal orderTotal = 0;

            var wishlistItems = GetWishListItems();
            // Iterate over the items in the wishlist, 
            // adding the order details for each
            foreach (var item in wishlistItems)
            {
                var orderDetail = new OrderDetail
                {
                    ProductId = item.ProductId,
                    OrderId = order.OrderId,
                    UnitPrice = item.Product.Price,
                    Quantity = item.Count
                };
                // Set the order total of the shopping wishlist
                orderTotal += (item.Count * item.Product.Price);

                storeDB.OrderDetails.Add(orderDetail);

            }
            // Set the order's total to the orderTotal count
            order.Total = orderTotal;

            // Save the order
            storeDB.SaveChanges();
            // Empty the shopping wishlist
            EmptyWishList();
            // Return the OrderId as the confirmation number
            return order.OrderId;
        }
        // We're using HttpContextBase to allow access to cookies.
        public string GetWishListId(HttpContextBase context)
        {
            if (context.Session[WishListSessionKey] == null)
            {
                if (!string.IsNullOrWhiteSpace(context.User.Identity.Name))
                {
                    context.Session[WishListSessionKey] =
                        context.User.Identity.Name;
                }
                else
                {
                    // Generate a new random GUID using System.Guid class
                    Guid tempWishListId = Guid.NewGuid();
                    // Send tempWishListId back to client as a cookie
                    context.Session[WishListSessionKey] = tempWishListId.ToString();
                }
            }
            return context.Session[WishListSessionKey].ToString();
        }
        // When a user has logged in, migrate their shopping wishlist to
        // be associated with their username
        public void MigrateWishList(string userName)
        {
            var shoppingWishList = storeDB.WishLists.Where(
                c => c.WishListId == ShoppingWishListId);

            foreach (WishList item in shoppingWishList)
            {
                item.WishListId = userName;
            }
            storeDB.SaveChanges();
        }
    }
}