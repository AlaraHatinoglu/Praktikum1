
//when an image is mirrored 1st pixel becomes the last, second becomes the 2nd before last!

#include <iostream>
#include<fstream>
#include<cstring> //might not be needed



using namespace std;

struct Pixel
{
    unsigned int red;
    unsigned int green;
    unsigned int blue;
};

class Image
{
private:
    char a;
    char b;

private:
    unsigned int width;
    unsigned int height;
    unsigned int max_value; //maximum color value

private:
    Pixel **r; //private pointer to a pointer of type Pixel, first * refers to x, second * refers to y.

public:
    cons1()
    {
        a = 'P';
        b = '3';
        width = 0;
        height = 0;
        max_value = 255;
        Pixel **r = nullptr;
    }

private:
    void alloc_raster ()
    {
      if((r = nullptr) || ((width > 0) || (height > 0)))
      {
          r = new Pixel*[height]; // allocate pointers to the rows //allocate: To reserve a portion of memory for use by a computer program.
          for (unsigned int k = 0; k < height; k++) // for all rows
          {
             r[k] = new Pixel[width]; // allocate pixels in row
          }

      }
      r[height][width];


    }

public: //2-6
    void read_ppm(string filename)
    {

        fstream readppm;
        char h1;
        string h2, h3, h4;
        readppm.open(filename);
        if(!readppm.is_open())
        {
            cout << filename << " cannot be opened!" << endl;
        }
        else
        {
           readppm >> a >> b >> width >> height >> max_value;
           cout << "\nread_ppm: " << filename << " opened...\n" << "\t  read header of file... \n"
           << "\t  allocate " << width << "x" << height <<" pixel array on heap... done\n"
           << "\t  read RGB pixel data row by row..." << endl;
           alloc_raster ();



           readppm >> h1 >> h2 >> h3>> h4;
//           cout << h1 << h2 << h3 << h4 << endl; //it takes the headers

           for(int a = 0; a < height; a++)
           {
               for(int b = 0; b < width; b++)
               {
                   readppm >> r[a][b].red >> r[a][b].green >> r[a][b].blue ;
               }
           }

           //cout << r[0][0].red << r[0][0].green << r[0][0].blue << endl; //it takes the pixels


           // 2 for loop one for width one for height in the 2nd one r[][]=red, blue green,

           readppm.close();
           cout << "\t  done and " << filename << " closed\n" << endl;

        }

    }

public:
     void mirror_vertically()
     {
         //alloc_raster ();
         Pixel temp;

         for(int a=0; a<(height); a++)
         {
           for(int b=0; b<width/2; b++)
            {
                temp = r[a][b];
//                r[a][b].red= r[height][width-b].red;
//                r[a][b].green = r[height][width-b].green;
//                r[a][b].blue =  r[height][width-b].blue;
                r[a][b] =  r[a][width-1-b];
                r[a][width-1-b] = temp;



            }
         }





         // public member function named mirror_vertically without parameter and without return. In the body, the image shall be mirrowed vertically, i.e. in each row the first
         //with the last pixel, the second with the second to last, etc. be exchanged.


         cout << "\tstart mirror image vertically...\n" << "\tdone" << endl;



     }

public:
    void write_ppm(string filename)
    {
        ofstream writeppm;
        string h1 = "# end of header";
        writeppm.open(filename);


        if(writeppm.is_open())
        {

//        alloc_raster ();
        writeppm << a << b << "\n" << width << " " << height << "\n" << max_value << "\n" << h1 << endl;


        for(int a = 0; a < height; a++)
           {
               for(int b = 0; b < width; b++)
               {
                   writeppm << r[a][b].red << " " << r[a][b].green << " " << r[a][b].blue << endl;
               }
           }


        cout << "\nwrite_ppm: " << filename << " opened...\n" << "\t    write header of file... \n"
        << "\t    write RGB pixel data row by row..." << endl;
        writeppm.close();
        cout << "\t    done and " << filename << " closed\n" << endl;
        }
    }

public:
    grayscale()
    {

        cout << "start grayscale filter..." << endl;

//        alloc_raster ();
        for(int a = 0; a < height; a++)
           {
               for(int b = 0; b < width; b++)
               {
                   r[a][b].red = ((r[a][b].red + r[a][b].green + r[a][b].blue)/3);
                   r[a][b].green = ((r[a][b].red + r[a][b].green + r[a][b].blue)/3);
                   r[a][b].blue =((r[a][b].red + r[a][b].green + r[a][b].blue)/3);
               }

           }
        cout << "done" << endl;

    }

public:
void frame(unsigned int f_width, unsigned int f_red, unsigned int f_green,  unsigned int f_blue )
{
    cout<<"\t  Start generating frame of width "<<f_width<<"..."<<endl;
      for(unsigned int a=0;a<f_width;a++)
      {
          for(unsigned int b=0; b<width;b++)
          {
                                r[a][b].red=f_red;
                                r[a][b].green=f_green;
                                r[a][b].blue=f_blue;

          }
      }


            for(unsigned int a=(height-f_width);a<height;a++)
      {
          for(unsigned int b=0; b<width;b++)
          {
                                r[a][b].red=f_red;
                                r[a][b].green=f_green;
                                r[a][b].blue=f_blue;

          }
      }

                  for(unsigned int a=0;a<height;a++)
      {
          for(unsigned int b=0; b<f_width;b++)
          {
                                r[a][b].red=f_red;
                                r[a][b].green=f_green;
                                r[a][b].blue=f_blue;

          }
      }

                        for(unsigned int a=0;a<height;a++)
      {
          for(unsigned int b=(width-f_width);b<width;b++)
          {
                                r[a][b].red=f_red;
                                r[a][b].green=f_green;
                                r[a][b].blue=f_blue;
          }
      }
        cout << "done" << endl;
   }
};

int main()
{
    //3-1
    Image image;
    string filename;
    int f_width, f_red, f_green, f_blue;

    //3-2
    char z;

    do
   {

       cout << "0 Ende                / end" << endl;
       cout << "1 lese .ppm Datei     / read .ppm file" << endl;
       cout << "2 vertikal spiegeln   / mirror vertically" << endl;
       cout << "3 schreibe .ppm Datei / write .ppm file" << endl;
       cout << "4 Graustufen                / grayscale" << endl;
       cout << "5 Rahmen                    / frame" << endl;
       cout << ">>" << ends;
       cin >> z;

    switch(z)
    {
       case '0' : break;

       case '1' :cout << "Please input file name: " << ends;
                 cin >> filename;
                 image.read_ppm(filename);
                 break;

       case '2' :image.mirror_vertically();
                 break;

       case '3' :cout << "Please input file name: " << ends;
                 cin >> filename;
                 image.write_ppm(filename);
                 break;

       case '4': {
           image.grayscale();
           break;
       }

       case '5': {cout << "Please input width of the frame: " << ends;
                  cin >> f_width;
                  cout << "Please input R G B values: " << ends;
                  cin >> f_red >> f_green >> f_blue;
                  image.frame(f_width, f_red, f_green, f_blue);
                  break;

       }

       default:    cout << "Please select a valid choice!" << endl;
       }
}
while(z != '0');

}
