﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class myData
    {
        public int up { get; set; }
        public int down { get; set; }
        public int count { get; set; }

        public override string ToString()
        {
            return string.Format("Nr values = {0}:{1}{2}",count-1,up,down);
        }
    }

    class Program
    {

   



        static void Main(string[] args)
        {
            //List<string> initData = new List<string>();
            //List<myData> myDataList = new List<myData>();


            

            List<int> upCountList = new List<int>();
            List<int> downCountList =new List<int>();

            int upCount = 0;
            int downCount = 0;
            int sameCount = 0;
            bool mark = true;
            for(int i=1;i<sequence.Count;i++)
            {
                if(sequence[i]>sequence[i-1])
                {
                    upCount += sameCount + 1;
                    mark = false;
                    sameCount = 0;
                }
                else if(sequence[i]<sequence[i-1])
                {
                    downCount += sameCount + 1;
                    mark = false;
                    sameCount = 0;
                }
                else if(sequence[i]==sequence[i-1]&&mark)
                {
                    sameCount++;
                }



            //while (true)
            //{
            //    string rawData = Console.ReadLine();
            //    if (rawData == "0")
            //    {
            //        break;
            //    }
            //    List<int> sequence = rawData.Split(' ').Cast<int>().ToList();
            //    int upCount = 0;
            //    int downCount = 0;
            //    int sameCount = 0;
            //    bool mark = true;
            //    for(int i=1;i<sequence.Count;i++)
            //    {
            //        if(sequence[i]>sequence[i-1])
            //        {
            //            upCount += sameCount + 1;
            //            mark = false;
            //            sameCount = 0;
            //        }
            //        else if(sequence[i]<sequence[i-1])
            //        {
            //            downCount += sameCount + 1;
            //            mark = false;
            //            sameCount = 0;
            //        }
            //        else if(sequence[i]==sequence[i-1]&&mark)
            //        {
            //            sameCount++;
            //        }
            //    }
            //}



        }
    }
}
