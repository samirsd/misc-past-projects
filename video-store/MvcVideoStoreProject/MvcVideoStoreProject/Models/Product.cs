using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations;
using System.Web.Mvc;

namespace MvcVideoStoreProject.Models
{
    [Bind(Exclude = "ProductId")]

    public class Product
    {
        [ScaffoldColumn(false)]
        public int ProductId { get; set; }
        //public int ProductTypeId { get; set; }
        //public int FormatId { get; set; }
        //public int GenreId { get; set; }
        //public int ProducerId { get; set; }
        //public int DirectorId{ get; set; }
        [DisplayName("Product Type")]
        public virtual ProductType ProductType { get; set; }
        
        public virtual Format Format { get; set; }
       
        public virtual Genre Genre { get; set; }
        public virtual Producer Producer { get; set; }
        public virtual Director Director { get; set; }

        [Required(ErrorMessage = "A Title is required")]
        [StringLength(160)]
        public string Title { get; set; }
        [Required(ErrorMessage = "Price is required")]
        public decimal Price { get; set; }

        public string ProductArtUrl { get; set; }

                        
    }
}

        //[DisplayName("Product Type")]
        //public virtual ProductType ProductType { get; set; }
        //[DisplayName("Format")]
        //public virtual Format Format { get; set; }
        //[DisplayName("Genre")]      
        //public virtual Genre Genre { get; set; }
        //[DisplayName("Producer")]        
        //public virtual Producer Producer { get; set; }
        //[DisplayName("Director")]        
        //public virtual Director Director { get; set; }

        //[Required(ErrorMessage = "A Title is required")]
        //[StringLength(160)]
        //public string Title { get; set; }
        //[Required(ErrorMessage = "Price is required")]
        //[Range(0.01, 100.00,
        //    ErrorMessage = "Price must be between 0.01 and 100.00")]
        //public decimal Price { get; set; }
        //[DisplayName("Product Art URL")]
        //[StringLength(1024)]
        //[Required(ErrorMessage = "URL is required")]
        //public string ProductArtUrl { get; set; }