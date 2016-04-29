using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace MvcVideoStoreProject.Models
{
    public class ProductType
    {
        public int ProductTypeId { get; set; }
        public virtual string Name { get; set; }

    }
}