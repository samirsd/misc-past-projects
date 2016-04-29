using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;

namespace MvcVideoStoreProject.Models
{
    public class VideoStoreEntities : DbContext
    {
        public DbSet<Product> Products { get; set; }
        public DbSet<Format> Formats { get; set; }
        public DbSet<Genre> Genres { get; set; }
        public DbSet<ProductType> ProductTypes { get; set; }
        public DbSet<Producer> Producers { get; set; }
        public DbSet<Director> Directors { get; set; }


        public DbSet<Cart> Carts { get; set; }
        public DbSet<WishList> WishLists { get; set; }
        public DbSet<Order> Orders { get; set; }
        public DbSet<OrderDetail> OrderDetails { get; set; }

    
        //public DbSet<BluRay> BluRays { get; set; }
        //public DbSet <DVD> DVDs { get; set; }
        //public DbSet<Genre> Genres { get; set; }


    }
}