using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using MvcVideoStoreProject.ViewModels;
using MvcVideoStoreProject.Models;

namespace MvcVideoStoreProject.Controllers
{
    public class ShoppingWishListController : Controller 
    {
        VideoStoreEntities storeDB = new VideoStoreEntities();
        //
        // GET: /ShoppingWishList/
        public ActionResult Index()
        {
            var wishlist = ShoppingWishList.GetWishList(this.HttpContext);
 
            // Set up our ViewModel
            var viewModel = new ShoppingWishListViewModel
            {
                WishListItems = wishlist.GetWishListItems(),
                WishListTotal = wishlist.GetTotal()
            };
            // Return the view
            return View(viewModel);
        }
        //
        // GET: /Store/AddToWishList/5
        public ActionResult AddToWishList(int id)
        {
            // Retrieve the product from the database
            var addedProduct = storeDB.Products
                .Single(product => product.ProductId == id);
 
            // Add it to the shopping wishlist
            var wishlist = ShoppingWishList.GetWishList(this.HttpContext);
 
            wishlist.AddToWishList(addedProduct);
 
            // Go back to the main store page for more shopping
            return RedirectToAction("Index");
        }
        //
        // AJAX: /ShoppingWishList/RemoveFromWishList/5
        [HttpPost]
        public ActionResult RemoveFromWishList(int id)
        {
            // Remove the item from the wishlist
            var wishlist = ShoppingWishList.GetWishList(this.HttpContext);
 
            // Get the name of the product to display confirmation
            string productName = storeDB.WishLists
                .Single(item => item.RecordId == id).Product.Title;
 
            // Remove from wishlist
            int itemCount = wishlist.RemoveFromWishList(id);
 
            // Display the confirmation message
            var results = new ShoppingWishListRemoveViewModel
            {
                Message = Server.HtmlEncode(productName) +
                    " has been removed from your shopping wishlist.",
                WishListTotal = wishlist.GetTotal(),
                WishListCount = wishlist.GetCount(),
                ItemCount = itemCount,
                DeleteId = id
            };
            return Json(results);
        }
        //
        // GET: /ShoppingWishList/WishListSummary
        [ChildActionOnly]
        public ActionResult WishListSummary()
        {
            var wishlist = ShoppingWishList.GetWishList(this.HttpContext);
 
            ViewData["WishListCount"] = wishlist.GetCount();
            return PartialView("WishListSummary");
        }
  

    }
}