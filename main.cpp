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
    if(a>12||a<0||b<0||b>31){   //�ж�����ĺϷ��ԣ�
       sum=0;
    }
    else{
        do{                     //֪�������������ڣ�do����while�����򵥣�
            sum+=day[i];
            i++;
        }while(i<a-1);
        sum+=b;
  /*  switch (a){                 //����switch���������ÿ���·ݵ�������
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

    cout<<endl<<"\t\t"<<a<<"��"<<b<<"��\t"<<endl;
    cout<<"SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT"<<endl;
     int week=display_week(a,b,1);    //�ж������·�һ�ŵ�������;
        if(Isleap(a)==1){           //����������λ�����ʱ����·ݼ�һ;
            day[1]+=1;
        }
    for(int i=0;i<week;i++){        //���һ��֮ǰ�Ŀո�;
        cout<<"   \t";
    }
    for(int i=1;i<=day[b-1];i++){   //������µ�����;
        cout<<i<<"\t";
        if((i+week)%7==0){          //�����������Ϊ7��ʱ����;
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
    j=Isleap(y);                 //�ж��Ƿ�Ϊ���ꣻ
    c=Total_day(m,d);           //������������
    h=display_week(y,m,d);      //�������ڣ�
    if(c==0){
            cout<<"wrong input!!!"<<endl;
    }
    else{
        if(j==1){
        cout<<y<<"��"<<m<<"��"<<d<<"��������";
        c+=1;
       }
        else{
        cout<<y<<"��"<<m<<"��"<<d<<"�ղ�������";
       // c-=1;
        }
        cout<<endl<<y<<"��"<<m<<"��"<<d<<"����"<<c<<"��"<<endl;
        cout<<y<<"��"<<m<<"��"<<d<<"��Ϊ";
        switch(h){
            case 1:cout<<"����һ";break;
            case 2:cout<<"���ڶ�";break;
            case 3:cout<<"������";break;
            case 4:cout<<"������";break;
            case 5:cout<<"������";break;
            case 6:cout<<"������";break;
            case 7:cout<<"������";break;
        }
        display_month(y,m,d);       //��ʾ�����·ݵ����ڣ�
        }
    return 0;
}
