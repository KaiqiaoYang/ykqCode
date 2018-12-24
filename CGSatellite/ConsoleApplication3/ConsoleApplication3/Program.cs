using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    public class YKQ
    {
        public static int[,] win;
        public static void initWin(int a,int b)
        {
            win = new int[a + 1, b + 1];
            win[0, 0] = -1;
            win[1, 0] = 1;
            win[0, 1] = 1;
        }

        public static int isWin(int a,int b)
        {
            if (win[a, b] != 0)
            {
                return win[a, b];
            }
            for (int i = 0; i < a; i++)
            {
                if (isWin(i, b) == -1)
                {
                    win[a, b] = 1;
                    return 1;
                }
            }
            for (int i = 0; i < b; i++)
            {
                if (isWin(i, b) == -1)
                {
                    win[a, b] = 1;
                    return 1;
                }
            }
            for (int i = Math.Min(a, b); i > 0; i--)
            {
                if (isWin(a - i, b - i) == -1)
                {
                    win[a, b] = -1;
                    return -1;
                }
            }
            win[a,b]=-1;
            return -1;
        }
        
        public static void Main()
        { 
         while(true)
         {
             var rawData = Console.ReadLine();
             if(rawData=="")
             {
                 break;
             }
             var rawDataList=rawData.Split(' ');

             int a =Convert.ToInt32(rawDataList[0]);
             int b =Convert.ToInt32(rawDataList[0]);

             YKQ.initWin(a, b);
             Console.WriteLine(YKQ.isWin(a, b));
         }
            
        }
    }
}
