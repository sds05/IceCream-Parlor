#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
//char size;
int cones=100,cup=100;			//stock=1;
class icecream
{ public:
  float price;
  char flavour[20],type[20];
  int scoops,icode,c;
  char size;
  void getdetails()
  {
    cout<<"Flavour : ";
    cin>>flavour;
    cout<<"Price : ";
    cin>>price;
    cout<<"Type : ";
    gets(type);
    cout<<"scoops : ";
    cin>>scoops;
    cout<<"code :";
    cin>>icode;
    cout<<endl;
  }

    void disp()
  { cout<<endl;
    cout<<"The details are :"<<endl;
    cout<<"Flavour : "<<flavour<<"\t";
    cout<<"Price : "<<price<<"\t";
    cout<<"Type : ";
    puts(type);
    cout<<"\t";
    cout<<"Code : "<<icode<<"\t";
    cout<<"scoops : "<<scoops;
    cout<<endl;
    cout<<"-------------------------------------------------------"<<endl;
  }



};
    void creates()
  { icecream ice;
  fstream fout;
  fout.open("icecream.dat",ios::out|ios::binary);
  for(int i=0;i<5;i++)
   { ice.getdetails();
     fout.write((char*)&ice,sizeof(ice));
   }

   fout.close();
  }
  void display()
  { icecream i;
   fstream fin;
   fin.open("icecream.dat",ios::in|ios::binary);
   fin.read((char*)&i,sizeof(i));
   while(!fin.eof())
   {
    i.disp();
    fin.read((char*)&i,sizeof(i));
   }
   fin.close();
 }

     void searchstock()
 {
  icecream i;
  fstream fin;
  int flag=0;
  char name[20],f[20];
  cout<<"Enter the flavour to be searched:";
  cin>>f;
  cout<<endl;
  fin.open("icecream.dat",ios::in|ios::binary);
  while(!fin.eof())
  {fin.read((char*)&i,sizeof(i));
   if((strcmpi(i.flavour,f)==0)&&(i.scoops!=0))
    {flag=1;
    break;  // JUST ADDED
    }
  }
   if(flag==1)
   {
   cout<<"The flavour "<<f<<" is available."<<endl;
   cout<<"Information of the searched flavour :"<<endl;
   cout<<"-------------------------------------"<<endl;
   cout<<"Flavour : "<<i.flavour<<endl;
   cout<<"Price : "<<i.price<<endl;
   cout<<"Scoops :"<<i.scoops<<endl;
   cout<<"Code : "<<i.icode<<endl;
   cout<<"-------------------------------------"<<endl;
   }

   else
   cout<<"The flavour "<<f<<" is not available."<<endl;

  fin.close();
 }
  void updflavour()
 {
  icecream i;
  char name[20];
  cout<<"Enter the flavour to be updated : ";
  cin>>name;
  fstream f("icecream.dat",ios::binary|ios::in|ios::out);
  while(!f.eof())
  { f.read((char*)&i,sizeof(i));
   if(strcmpi(i.flavour,name)==0)
   { cout<<"Enter updated flavour info :";
   f.seekg(-1*sizeof(i),ios::cur);
   i.getdetails();
   f.write((char*)&i,sizeof(i));
   cout<<"Flavour updated successfully ."<<endl;
   cout<<"--------------------------------"<<endl;
   }
  }
 f.close();

 }
   void menu()
 {
   icecream i;
   fstream fin;
   fin.open("icecream.dat",ios::in|ios::binary);
   cout<<"----WELCOME TO GOLDEN CONFETTI ICE CREAM PALOUR-----"<<endl;
   cout<<"----------------------MENU--------------------------"<<endl;
   cout<<"           Flavour        Price"<<endl;
   cout<<"----------------------------------------------------"<<endl;
   while(!fin.eof())
   {
     fin.read((char*)&i,sizeof(i));

   cout<<"           "<<i.flavour<<"          "<<i.price<<endl;
   }
   cout<<"----------------------------------------------------"<<endl;

   fin.close();
 }

 void order()
 {
   icecream i,ice[10];
   int n,j,k=0,l,co;
   float amount=0,totall;
   char flav[20];
   fstream fin;
   fin.open("icecream.dat",ios::in|ios::binary|ios::out);
   cout<<endl;
   cout<<"Enter order :"<<endl;
   cout<<"Enter the number of ice creams you want to buy: ";
   cin>>n;
     for(j=0;j<n;j++)
     { cout<<"Enter flavour of icecream #"<<j+1 <<":";
       cin>>flav;
       cout<<"Cup or cone ? Press 0 for cup and 1 for cone : ";
       cin>>co;
	 while(!fin.eof())
	{
	   fin.read((char*)&i,sizeof(i));
	   if(strcmpi(i.flavour,flav)==0)
	   {
	    strcpy(ice[k].flavour,i.flavour);
	    ice[k].price=i.price;
	    ice[k].c=co;
	    i.scoops--;
		amount=amount+i.price;
		k++;
		break;
	   }
       }
       }
       cout<<endl;
     cout<<"--------------------------------------------------"<<endl;
     cout<<"Your order is.."<<endl;
     for(l=0;l<k;l++)
     {
     cout<<"flavour : "<<ice[l].flavour<<"......."<<"price : DHS"<<ice[l].price<<endl;
      { if(ice[l].c==0)
	cout<<"cup/cone -> cup"<<endl;
	else if(ice[l].c==1)
	cout<<"cup/cone -> cone"<<endl;
      }
     }

     cout<<"Sub total amount.....................DHS "<<amount<<endl;
     totall=amount+(0.05*amount);
     cout<<"total amount(including 5% vat).......DHS "<<totall<<endl;
     cout<<endl;

     cout<<"Thank you for ordering."<<endl;
     cout<<"Please come again."<<endl;
     cout<<"--------------------------------------------------"<<endl;

  fin.close();
 }


   void deleteflavour()
 {
   char dflavour[10];
   icecream i;
   fstream fin,fout;
   cout<<"Enter the ice cream flavour to be deleted"<<"\n";
   cin>>dflavour;
   fout.open("temp.dat",ios::out|ios::binary);
   fin.open("icecream.dat",ios::in|ios::binary);
   while(!fin.eof())
   { fin.read((char*)&i,sizeof(i));
     if((strcmpi(dflavour,i.flavour)>=0)||(strcmpi(dflavour,i.flavour)<=0))
     { fout.write((char*)&i,sizeof(i));}
   }
   cout<<endl;
   cout<<"Flavour successfully deleted"<<endl;
   fin.close();
   fout.close();
   remove("icecream.dat");
   rename("temp.dat","icecream.dat");


 }
  void append()
 { int k,j,n;
   icecream i;
   fstream fout;
   fout.open("icecream.dat",ios::app|ios::binary);
   cout<<"Number of flavours to be added"<<'\n';
   cin>>n;
   for(j=0;j<n;j++)
   {i.getdetails();
    fout.write((char*)&i,sizeof(i));
   }
   cout<<"Flavour successfully added .";
   fout.close();
}

 void month()
 {icecream i;
  int flag=0;
  fstream fin;
  fin.open("icecream.dat",ios::in|ios::binary);
  while(!fin.eof())
  {
   fin.read((char*)&i,sizeof(i));
   if(strcmpi(i.type,"special")==0)
   {
   cout<<endl;
   cout<<"***********SPECIAL**************"<<endl;
   cout<<"------FLAVOUR OF THE MONTH------"<<endl;
   cout<<"Flavour : "<<i.flavour<<endl;
   cout<<"Price : "<<i.price<<endl;
   cout<<"Scoops :"<<i.scoops<<endl;
   cout<<"Code : "<<i.icode<<endl;

   cout<<"--------------------------------"<<endl;
   flag=1;
   cout<<endl;
   }
  }
  if(flag==0)
  cout<<"Flavour of the month not found."<<endl;
  fin.close();
}

 void sort()
 {
  icecream ice[10],temp;
  int i=0,j,n=0;
  fstream fin("icecream.dat",ios::in);
  while(!fin.eof())
  {
   fin.read((char*)&ice[n],sizeof(ice[n]));
   n++;
  }

  for(i=0;i<n;i++)
   for(j=0;j<n-i;j++)
   {
    if(ice[j].price>ice[j+1].price)
    {
      temp=ice[j];
      ice[j]=ice[j+1];
      ice[j+1]=temp;
    }
   }

    ofstream fout("icecream.dat",ios::out|ios::binary);
    cout<<"---------------------------------"<<endl;
    for(i=0;i<n;i++)
    {
    fin.write((char*)&ice[i],sizeof(ice[i]));
    cout<<"Flavour : "<<ice[i].flavour<<"\t";
    cout<<"Price : "<<ice[i].price<<endl;
    cout<<"Scoops :"<<ice[i].scoops<<"\t";
    cout<<"Code : "<<ice[i].icode<<endl;
    cout<<"---------------------------------"<<endl;
    }
    fout.close();
 }



  void main()
 {
   clrscr();

   creates();
   int ch,c,j;

   do
   {
     cout<<"-----------------------------------------------------------------------"<<endl;
     cout<<"1:Menu                                6:To sort the icecreams in the"<<endl;
     cout<<"2:To display complete                   order of increasing price"<<endl;
     cout<<"info of all the ice creams            7:Add flavours"<<endl;
     cout<<"3:Place Order and Display bill        8:Updating Stock"<<endl;
     cout<<"4:To view the flavour of the          9:Remove flavours"<<endl;
     cout<<"month                                 10: Exit"<<endl;
     cout<<"5:Search For Stock"<<"\n";
     cout<<"-------------------------------------------------------------------------"<<endl;

     cout<<"Enter Choice"<<"\n";

     cin>>ch;
     switch(ch)
     { case 1: menu();
	       break;
       case 2: display();
	       break;
       case 3: order();
	       break;
       case 4: month();
	       break;
       case 5: searchstock();
	       break;
       case 6: sort();
	       break;
       case 7: append();
	       break;
       case 8: updflavour();
	       break;
       case 9: deleteflavour();;
	       break;

       default:cout<<"Invalid choice"<<'\n';
	       break;
      }
    }while(ch!=10);
      getch();
  };




