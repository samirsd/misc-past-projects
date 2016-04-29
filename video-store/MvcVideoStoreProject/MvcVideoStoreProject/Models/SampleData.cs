using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;

namespace MvcVideoStoreProject.Models
{
    public class SampleData : DropCreateDatabaseAlways<VideoStoreEntities>
    {
        protected override void Seed(VideoStoreEntities context)
        {

            
            var producttypes = new List<ProductType>
            {

                new ProductType { Name = "Movie"},
                new ProductType { Name = "Snack"}
            };

            var formats = new List<Format>
            {

                new Format { Name = "BluRay"},
                new Format { Name = "DVD"},
                new Format { Name = "Stream"}

            };

            var producers = new List<Producer>
            {

                new Producer { Name = "Jean-Luc Godard"},
                new Producer {Name = "Stephen Spielberg"}
            };


            var directors = new List<Director>{

                new Director {Name = "Woody Allen"}

            };

            var genres = new List<Genre>
            {

                new Genre { Name = "Comedy" },
                new Genre { Name = "Horror" },
                new Genre { Name = "Neo-noir"},
                new Genre { Name = "Sci-Fi"}

            };
                      
            
            new List<Product>{

                new Product {Title = "Jurassic Park", Genre = genres.Single(g => g.Name == "Sci-Fi"),  Producer = producers.Single(p=>p.Name == "Stephen Spielberg"),
                    ProductArtUrl = "~/Content/img/dvd1.jpg", ProductType = producttypes.Single(pt => pt.Name == "Movie"), Format = formats.Single(f => f.Name == "DVD")},
                new Product {Title = "Star Wars", Genre = genres.Single(g => g.Name == "Sci-Fi"), Producer = producers.Single(p=>p.Name == "Stephen Spielberg"),
                    ProductArtUrl = "~/Content/img/dvd2.jpg", ProductType = producttypes.Single(pt => pt.Name == "Movie"), Format = formats.Single(f => f.Name == "BluRay")},
                new Product {Title = "Lord Of The Rings", Genre = genres.Single(g => g.Name == "Sci-Fi"), Producer = producers.Single(p=>p.Name == "Stephen Spielberg"),
                    ProductArtUrl = "~/Content/img/dvd3.jpg", ProductType = producttypes.Single(pt => pt.Name == "Movie"), Format = formats.Single(f => f.Name == "BluRay")},
                 new Product {Title = "The Exorcist", Genre = genres.Single(g => g.Name == "Sci-Fi"), Producer = producers.Single(p=>p.Name == "Stephen Spielberg"),
                    ProductArtUrl = "~/Content/img/dvd4.jpg", ProductType = producttypes.Single(pt => pt.Name == "Movie"), Format = formats.Single(f => f.Name == "Stream")},

           

            }.ForEach(a => context.Products.Add(a));

            producttypes.ForEach(pt => context.ProductTypes.Add(pt));
            formats.ForEach(f => context.Formats.Add(f));
            genres.ForEach(g => context.Genres.Add(g));
            producers.ForEach(p => context.Producers.Add(p));
            directors.ForEach(d => context.Directors.Add(d));

            
 

            //new List<Album>
            //{
            //    
            //new Album { Title = "The Best Of Men At Work", Genre = genres.Single(g => g.Name == "Rock")
            //, Price = 8.99M, Producer = producers.Film(a => a.Name == "Men At Work"), AlbumArtUrl = "/Content/Images/placeholder.gif" },
            //    new Album { Title = "Ao Vivo [IMPORT]", Genre = genres.Film(g => g.Name == "Latin"), Price = 8.99M, Producer = producers.Film(a => a.Name == "Zeca Pagodinho"), AlbumArtUrl = "/Content/Images/placeholder.gif" },
            //}.ForEach(a => context.Albums.Add(a));
        }
    }
}

//var videos = new List<Video>{


//    new Video { Format = formats.Single(f=> f.Name == "BluRay"), Title = "Breathless", Genre = genres.Single(g => g.Name == "Neo-noir"),
//        Price = 8.99M, Producer = producers.Single(p => p.Name == "Jean-Luc Godard"),
//        VideoArtUrl = "/Content/Images/placeholder.gif" }


//};


//var formats = new List<Format>
//{

//    new Format { Name = "BluRay"},
//    new Format { Name = "DVD"}

//};


//var producers = new List<Producer>
//{
//    new Producer { Name = "Steven Spielberg" },
//    new Producer { Name = "Jean-Luc Godard" },
//};



// var products = new List<Product>{

//    new Product { Title = "Breathless" , ProductType = "Movie", Format = formats.Single(f => f.Name == "BluRay"), Producer = producers.Single(p => p.Name == "Jean-Luc Godard") },
//    new Product { ProductType = "Snack"}

//};