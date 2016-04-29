using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using MvcVideoStoreProject.Models;
namespace MvcVideoStoreProject.ViewModels
{
    public class ShoppingWishListViewModel
    {
        public virtual List<WishList> WishListItems { get; set; }
        public decimal WishListTotal { get; set; }
    }
}