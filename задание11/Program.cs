using System;
using System.Text.RegularExpressions;
using System.IO;
using System.Xml;
using System.Collections.Specialized;

namespace RegExpLab
{
    class Program
    {
        static void Main(string[] args)
        {
            //string str = " фыидо, fjbld33- 2олт? aaa";
            //Console.WriteLine(str); 

            // d Regex re = new Regex(@"\w*[0-9]+\w*");
            // g Regex re = new Regex(@"\w*(\w)\1+\w*");
            //Regex re = new Regex(@"\w*(\w)\1+\w*");

            //Regex re5 = new Regex(@"(\W*)(\w+)(\W+)(\w+)(\W+)(\w+)(\W*)");
            // Console.WriteLine(re5.Replace(str, "$1$4$3$2$5$6$7"));

            //i Regex re = new Regex(@"\b[a-zA-Z0-9]+\b");
            //j Regex re = new Regex(@"\w*[a-zA-Z]+\w*");
            //Regex re;

            //MatchCollection mc = re.Matches(str);
            //foreach (var m in mc)
            //    Console.WriteLine(m);
            //string s = Console.ReadLine();

            string orig;
            try
            {
                using (StreamReader sr = new StreamReader("Dictionary.xml"))
                {
                    orig = sr.ReadToEnd();
                    Console.WriteLine(orig.Length);
                }

            }
            catch (Exception ex)
            {
                Console.WriteLine("Ошибка чтения файла: \"Dictionary.xml\"\n{0}", ex);
                return;
            }

            // Исправленния букв раздела

            //Regex re = new Regex(@"<([a-z]+)>[^<>]*</\1>");
            //<italic> - П
            //Regex re = new Regex(@"(<([\w-]+)>)?\s*<(((?!italic).)*)>\s*(?<letter>[А-Я])\s*</\3>\s*(</([\w-]+)>)?");
            //Regex re = new Regex(@"(<([\w-]+)>)?\s*<(((?!italic).)*)>\s*(?<letter>[А-Я])\s*</\3>\s*(</\2>)?");
            Regex re = new Regex(@"((<(?<open>([\w-]+))>)\s*<(((?!italic).)*)>\s*(?<letter>[А-Я])\s*</\4>\s*(?(\k<open>)|)(</(\k<open>)>)\s*)|(\s*<(((?!italic).)*)>\s*(?<letter>[А-Я])\s*</\9>\s*)");
            var mc = re.Matches(orig);
            string transformed = "";

            //Выявленние всех букв раздела
            //foreach (var m in mc)
            //{
            //    Console.WriteLine(m.ToString());
            //}

            //Исправленние всех букв раздела
            transformed = re.Replace(orig, "\n<letter><bold>${letter}</bold></letter>\n");
            //Console.WriteLine(transformed);

            //Проверка на строке transformed
            //var mc1 = re.Matches(transformed);
            //foreach (var m in mc1)
            //{
            //    Console.WriteLine(m.ToString());
            //}



            //Регулярное выражение, которое выявляет “неправильные” (не <main-word> за буквой начала раздела) теги
            Regex re1 = new Regex(@"<letter><bold>(?<letter>[А-Я])</bold></letter>(.*|\s*)<((?!main-word)([a-z]+))></\2>");
            var mc1 = re1.Matches(transformed);

            //Спорные моменты
            //Regex re1 = new Regex(@"<letter><bold>(?<letter>[А-Я])</bold></letter>(.*|\s*)(<([a-z]+)>)*<(main-word)></\4>");
            //var mc1 = re1.Matches(transformed);

            //Вывод всех всех таких ошибок
            //foreach (var m in mc1)
            //{
            //    Console.WriteLine(m.ToString());
            //}

            transformed = re1.Replace(transformed, "\n<letter><bold>${letter}</bold></letter>\n");
            //Console.WriteLine(transformed);

            //Проверка на строке transformed
            //var mc2 = re1.Matches(transformed);
            //foreach (var m in mc2)
            //{
            //    Console.WriteLine(m.ToString());
            //}

            string path = "test.txt";
            try
            {

                using (StreamWriter sw = new StreamWriter(path))
                {
                    sw.Write(transformed);
                    Console.WriteLine(transformed.Length);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Ошибка сохранений в файл: \"{0}\"\n{1}", path, ex);
                return;
            }

            XmlDocument doc = new XmlDocument();
            doc.LoadXml(transformed);


            Console.ReadLine();

        }
    }
}
