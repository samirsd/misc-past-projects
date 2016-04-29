using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using MvcVideoStoreProject.Models;

namespace MvcVideoStoreProject.ViewModels
{
    public class ShoppingCartViewModel
    {
        public virtual List<Cart> CartItems { get; set; }
        public decimal CartTotal { get; set; }
    }
}