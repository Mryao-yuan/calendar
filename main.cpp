#include <iostream>

using namespace std;

int Isleap(int a){

    if((a%4==0&&a%100!=0)||a%400==0){
      return 1;
    }
    else{
        return 0;
    }

}
int Total_day(int a,int b){
    int sum=0,i=0;
    int day[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(a>12||a<0||b<0||b>31){   //判断输入的合法性；
       sum=0;
    }
    else{
        do{                     //知道结束结束调节，do——while语句更简单；
            sum+=day[i];
            i++;
        }while(i<a-1);
        sum+=b;
  /*  switch (a){                 //利用switch语句来计算每个月份的天数；
        case 1:sum=b;break;
        case 2:sum=31+b;break;
        case 3:sum=60+b;break;
        case 4:sum=91+b;break;
        case 5:sum=121+b;break;
        case 6:sum=152+b;break;
        case 7:sum=182+b;break;
        case 8:sum=213+b;break;
        case 9:sum=244+b;break;
        case 10:sum=274+b;break;
        case 11:sum=305+b;break;
        case 12:sum=335+b;break;
    */

    }

    return sum;
    }
int display_week(int a,int b,int c){
    int f=0;
    if(b==1||b==2){
        b+=12;
        a-=1;
    }
    f=(c+2*b+3*(b+1)/5+a+a/4-a/100+a/400+1)%7;
    return f;
}
void display_month(int a,int b,int c){

    int day[]={31,28,31,30,31,30,31,31,30,31,30,31};

    cout<<endl<<"\t\t"<<a<<"年"<<b<<"月\t"<<endl;
    cout<<"SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT"<<endl;
     int week=display_week(a,b,1);    //判断输入月份一号的星期数;
        if(Isleap(a)==1){           //当输入年数位闰年的时候二月份加一;
            day[1]+=1;
        }
    for(int i=0;i<week;i++){        //输出一号之前的空格;
        cout<<"   \t";
    }
    for(int i=1;i<=day[b-1];i++){   //输出该月的日期;
        cout<<i<<"\t";
        if((i+week)%7==0){          //当输入的日期为7天时换行;
         cout<<endl;
        }
        }
return ;
}
int main()
{
    int day[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int y=0,m=0,d=0,j,c=0,h;
    cout << "Please input a date:" << endl;
    cin>>y>>m>>d;
    j=Isleap(y);                 //判断是否为闰年；
    c=Total_day(m,d);           //计算总天数；
    h=display_week(y,m,d);      //计算星期；
    if(c==0){
            cout<<"wrong input!!!"<<endl;
    }
    else{
        if(j==1){
        cout<<y<<"年"<<m<<"月"<<d<<"日是闰年";
        c+=1;
       }
        else{
        cout<<y<<"年"<<m<<"月"<<d<<"日不是闰年";
       // c-=1;
        }
        cout<<endl<<y<<"年"<<m<<"月"<<d<<"日有"<<c<<"天"<<endl;
        cout<<y<<"年"<<m<<"月"<<d<<"日为";
        switch(h){
            case 1:cout<<"星期一";break;
            case 2:cout<<"星期二";break;
            case 3:cout<<"星期三";break;
            case 4:cout<<"星期四";break;
            case 5:cout<<"星期五";break;
            case 6:cout<<"星期六";break;
            case 7:cout<<"星期日";break;
        }
        display_month(y,m,d);       //显示输入月份的日期；
        }
    return 0;
}
