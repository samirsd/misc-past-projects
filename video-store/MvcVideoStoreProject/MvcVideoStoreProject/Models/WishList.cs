using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace MvcVideoStoreProject.Models
{
    public class WishList
    {

        public int RecordId { get; set; }
        public string WishListId { get; set; }
        public int ProductId { get; set; }
        public int Count { get; set; }
        public System.DateTime DateCreated { get; set; }
        public virtual Product Product { get; set; }
    }
}