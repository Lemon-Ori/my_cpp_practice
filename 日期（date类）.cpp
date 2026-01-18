// ===  ↓↓↓↓  提交代码开始  ↓↓↓↓  ============    
#include <iostream>
#include <string>
 
//Date类 声明
class Date
{
public:
    Date(int y = 1900, int m = 1, int d = 1);
    Date(const Date &dt);
 
 	Date operator+(int n) {
        if (n >= 0) return this->next(n);
        else return this->prev(-n);
    }
    
    bool operator==(const Date &dt) const {
        return (year == dt.year && month == dt.month && day == dt.day);
    }
    
    Date next(int n = 1); // n天后
    Date prev(int n = 1); // n天前
    void display(const std::string &format = "YYYY-MM-DD");
 
    int getYear() const;
    void setYear(int year);
 
    int getMonth() const;
    void setMonth(int month);
 
    int getDay() const;
    void setDay(int day);
 
 	bool isNotionalDay()
 	{
 		return(month==10&&day==1);
	 }
private:
    // 判断闰年
    bool isLeap(int year)
    {
        return ((!(year % 4) && year % 100) || !(year % 400));
    }
    // 获取某年给定月份的最后一天
    int getLastDayInMonth(int year, int m);
 
 	
private:
    // 属性(数据)
    int year;
    int month;
    int day;
};
 
//Date类 定义/实现
Date::Date(int y, int m, int d) : year(y), month(m), day(d)
{
}
 
Date::Date(const Date &dt) : year(dt.year), month(dt.month), day(dt.day)
{
}
 
Date Date::next(int n)
{
    // TODO
    int d = day;
    int m = month;
    int y = year;
 
    for (int i = 0; i < n; i++)
    {
        d++;
        if (d <= getLastDayInMonth(y, m))
        {
            continue;
        }
 
        d = 1, m++;
 
        if (m > 12)
        {
            y++, m = 1;
        }
    }
 
    return Date(y, m, d);
}
 
Date Date::prev(int n)
{
    // TODO
    int d = day;
    int m = month;
    int y = year;
 
    for (int i = 0; i < n; i++)
    {
        d--;
        if (d > 0) continue;
 
        (m - 1 < 1) ? m = 12, y-- : m--;
        d = getLastDayInMonth(y, m);
    }
 
    return Date(y, m, d);
}
 
void Date::display(const std::string &format)
{
    if (format == "YYYY-MM-DD")
    {
        printf("%d-%02d-%02d", year, month, day);
    }
    else if (format == "YYYY.MM.DD")
    {
        printf("%d.%d.%d", year, month, day);
    }
    else
    {
        printf("invalid format for displaying.");
    }
}
 
inline int Date::getYear() const
{
    return year;
}
inline void Date::setYear(int year)
{
    this->year = year;
}
 
int Date::getMonth() const
{
    return month;
}
void Date::setMonth(int month)
{
    this->month = month;
}
 
int Date::getDay() const
{
    return day;
}
void Date::setDay(int day)
{
    this->day = day;
}
 //往上看
int Date::getLastDayInMonth(int year, int m)
{
    int mdays = 30;
    // TODO
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        mdays = 31;
        break;
    case 2:
        (isLeap(year)) ? mdays = 29 : mdays = 28;
    }
 
    return mdays;
}
 
//===  ↑↑↑↑  提交代码结束  ↑↑↑↑  ============     
 
 
//////// → 提交的代码不包含主函数 ← ////////
int main()
{   
    int y, m, d, n;
    std::cin >> y >> m >> d >> n;
    Date theDay(y, m, d);
 
    // 加法运算符支持与负数相加, 表示回退到早前的日期。
    // 注: 实现 + 和 - 运算符时, 可复用已有的成员函数。
    Date dt = theDay + n;
 
    if (dt.isNotionalDay()) // 判断是否国庆日
    {
        dt.display("YYYY.MM.DD");
        std::cout << ", the National Day of China." << std::endl;
        return 0;
    }
 
    Date theDayOfWH(2020, 4, 8);
    if (dt == theDayOfWH) // 判断是否某特定日期
    {
        dt.display("YYYY.MM.DD");
        std::cout << ", the day Wuhan restarted!" << std::endl;
        return 0;
    }
 
    dt.display();
 
    return 0;
}   