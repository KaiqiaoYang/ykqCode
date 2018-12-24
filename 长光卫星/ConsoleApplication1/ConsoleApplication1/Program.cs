using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        const double MIN = 0.00;
        const double MAX = 5.20;
        
        static int getCardsNum(double c)
        {
            double length = 0;
            int count = 2;
            while(length<c)
            {
                length += (float)1.0/count;
                count++;
            }
            return count-2;
        }

        static void Main(string[] args)
        {
            List<float>mValue=new List<float>();
            while(true)
            {
                float length =Convert.ToSingle(Console.ReadLine());
                if(length==0)
                {
                    break;
                }
                if(length>MAX||length<MIN)
                {
                    Console.WriteLine("error!");
                }
                else
                {
                    Console.WriteLine(getCardsNum(length).ToString()+"card(s)");
                }
            }
         


            }

        }
    }

