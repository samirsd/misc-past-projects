using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using MvcVideoStoreProject.Models;

namespace MvcVideoStoreProject.Controllers
{
    public class HomeController : Controller
    {
        public class ViewProducts
        {
            public IEnumerable<Product> products;
            public string title;
        }

        VideoStoreEntities storeDB = new VideoStoreEntities();
        //
        // GET: /Home/

        public ActionResult Index()
        {
            var products = storeDB.Products.ToList();

            return View(products);
        }


        //public ActionResult Browse(string genre)
        //{
        //    // Retrieve Genre and its Associated Albums from database
        //    var genreModel = storeDB.Genres.Include("Albums")
        //        .Single(g => g.Name == genre);

        //    return View(genreModel);
        //}

        //
        // GET: /Home/Browse?product=product
        public ActionResult Browse(string product)
        {           

            var filterProduct = storeDB.Products.Where(x => x.Format.Name == product).ToList();


            //var result = new ViewProducts() { title = product, products = products };


            //var products = storeDB.Videos.Where(x => x.Format == product);

            return View(product, filterProduct);

        }

        public ActionResult Genre(string genre)
        {
            var genreModel = new Genre { Name = genre };
            return View(genreModel);
        }



        //
        // GET: /Store/Details/5
        public ActionResult Details(string title)
        {


            var detail = storeDB.Products.Single(x => x.Title ==  title);

            return View(detail);
        }

        public ActionResult Snacks(string title)
        {


            var detail = storeDB.Products.Single(x => x.Title == title);

            return View(detail);
        }



        //public System.Data.Entity.DbSet<Product> getItemByTitle(string title){


        //    var item = storeDB.Products.Single(x => x.Title == title);
        //    return item;
        //    }


        //
        // GET: /Home/DVD

        //public ActionResult DVD()
        //{
            

        //    return View();
        //}

        //
        // GET: /Home/BLURAY
        //public ActionResult BluRay()
        //{
        //    var products = storeDB.Videos.Where(x => x.Format == "BluRay" );

        //    return View("Video", products);
           
        //}

        //
        // GET: /Home/STREAM

        //public ActionResult Stream()
        //{

        //    return View();
        //}

        //
        // GET: /Home/SNACKS

        //public ActionResult Snacks()
        //{
        //    var products = storeDB.Products.Where(x => x.ProductType == "Snack");

        //    return View("Snacks", products);
        
        //}

    }
}
