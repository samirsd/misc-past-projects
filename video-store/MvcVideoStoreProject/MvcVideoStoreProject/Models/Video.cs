using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace MvcVideoStoreProject.Models
{
    public class Video
    {
        public int VideoId { get; set; }
        public int GenreId { get; set; }
        public int ProducerId { get; set; }
        public string Title { get; set; }
        public decimal Price { get; set; }
        public string VideoArtUrl { get; set; }
        public Genre Genre { get; set; }
        public Format Format { get; set; }
        public Producer Producer { get; set; }
    }
}