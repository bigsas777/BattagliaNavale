//23_Savastano e 24_Tariq
//3^C IA   inizio: 19/01/2021    consegna: 02/02/2021
#include <iostream>
using namespace std;

struct navi
{
  int Uno;
  int Due;
  int Tre;
  int Quattro;	
	
};


void introduzione()
     {
      cout<<"Benvenuti comandanti!\n";
      cout<<"Questa sara' una battaglia per la vita, siete pronti?\n";
      cout<<"Cosa volete fare?\n"; 
      return;    
     }  

void menu()
     {
      cout<<"[0] e' troppo presto, meglio aspettare prima di scatenare una guerra\n";
      cout<<"[1] Conoscere le regole della battaglia, bisogna vincere in modo leale\n";    
      cout<<"[2] Iniziare i preparativi! \n";     
      return;    
     }

void regole()
     {
     	cout<<"Questa non e' una semplice battaglia navale, e' una guerra vera e propria!\n";
     	cout<<"Come vincere? semplice. Bisogna affondare l'intera flotta nemica.\n";
     	cout<<"Ogni comandante deve disporre la sua flotta. Il numero di navi e la loro dimensione viene concordata dai comandanti.\n";
     	cout<<"Due navi non possono toccarsi.\n";
     	cout<<"A turno, i comandanti dovranno dire le coordinate di un punto sulla mappa e in quel punto verra' effettuata una sparata.\n";
     	cout<<"Verra' segnata ogni sparata in una tabella accessibile da entrambi i comandanti.\n";
     	cout<<"Se una nave viene colpita in tutta la sua dimensione sara' affondata\ne il comandate che ha subito la perdita dovra' annunciare che e' stata 'colpita e affondata'!\n\n";
     	return;
     }     

void preparazione()
     {
      cout<<"Decitede cosa fare e poi, iniziate la battaglia!\n";
      cout<<"[0] Penso non sia ancora il momento giusto..\n";
      cout<<"[1] Disporre le flotte\n";
      cout<<"[2] Riposizionare le flotte, meglio essere sicuri di fare la scelta migliore\n";
      cout<<"[3] E' il momento! Che la battaglia abbia inizio!\n";    
      return;    
     } 
	   
void riposizionamento()
     {
        cout<<"Va bene comandanti, e' sempre meglio essere sicuri!\n";
        cout<<"Chi dei due comandanti vuole cambiare flotta?\n";
        cout<<"[0] In realta' non serve, siamo pronti!\n";
        cout<<"[1] Solo il primo comandante!\n";
        cout<<"[2] Solo il secondo comandante!\n";
        cout<<"[3] Entrambi i comandanti!\n";     	
     	return;
	 }	             

void svuotaMatrice(int m[10][10])
     {
      int r,c;
      for(r=0;r<10;r++)
         {  
           for(c=0;c<10;c++)
              { 
               m[r][c]=0;
               }
          }
          return;
     }
     
 
int convertitore(char a)   //convertitore da ASCII a numero
    {
     int numero;
     numero=a-65;
 
     return numero;   
    }  
     
void inserimentoFlotte(int m[10][10],int tot,navi a)   //inserimento delle navi sul campo
    {
	 int r=0,c,i,s;
     char cc;
	 bool ripetere=false;
	 bool ripInt=false;
	 int direzione=0;	
	 do
	  {
	  for(i=0;i<tot;i++)              //ciclo for per far ripetere la selezione della nave della da inserire
	     {
	      ripetere=false;
		  direzione=0;	
		  cout<<"Dimensione della nave da inserire: ";        
		  cin>>s;
		  if(s==1)                    //if per le navi di dimensione 1, niente richiesta della direzione
		    {
		      for(int j=0;j<a.Uno;j++)
		    	 {
		    	 	do
		    	 	{
					 cout<<"inserire la Riga:";
                     cin>>r;
                     cout<<"Inserire la colonna:";
                     cin>>cc;
                     c=convertitore(cc);
                     if(c>9 || r>9)
                        {
                          	cout<<"Il numero inserito e' troppo grande! Reinserire\n";
                          	ripetere=true;
						} 
					 else
					    {
					        ripetere=false;	
					    }		      
                    }while(ripetere==true);
                    m[r-1][c]=1;
			     }
			  tot=tot-a.Uno;	 	
			}
		  if(s==2)
		    {
		      for(int j=0;j<a.Due;j++)
			     { 
			      do
				   {
				      do
					   {	
			     	     cout<<"In che direzione va inserita la nave?";
			     	     cout<<"[1] Sinistra, [2] Destra, [3] Verso l'alto, [4] Verso il basso";
			     	     cin>>direzione;
			             cout<<"inserire la Riga di partenza:";
                         cin>>r;
                         cout<<"Inserire la Colonna di partenza:";
                         cin>>cc;
                         c=convertitore(cc);
                         if(c>10 || r>10)
                            {
                            	cout<<"Il numero inserito e' troppo grande! Reinserire\n";
                            	ripetere=true;
						    }	
					     else
					        {
					        	ripetere=false;
						    }   
                       }while(ripetere==true);
                    m[r-1][c]=1;
                    if(direzione==1 && c<=0)
                       {
                       	cout<<"La nave esce dalla mappa! Reinserire\n";
                       	ripInt=true;
					   }
					if(direzione==1 && c>=2)
					   {
					   	m[r-1][c-1]=1;
					   }       
					if(direzione==2 && c>9 )
					   {
					    cout<<"La nave esce dalla mappa! Reinserire\n";	
					    ripInt=true;
				       }
					if(direzione==2 && c<=10)
					   {
					   	m[r-1][c+1]=1;
					   }       
					if(direzione==3 && r<=1)
					   {
					    cout<<"La nave esce dalla mappa! Reinserire\n";
						ripInt=true;
					   }
					if(direzione==3 && r>=2)
					   {
					   	m[r-2][c]=1;
					   }   
					if(direzione==4 && r>=9)
					   {
					    cout<<"La nave esce dalla mappa! Reinserire\n";
						ripInt=true;	
					   }
					if(direzione==4 && r<=9)
					   {
					   	m[r][c]=1;
					   }   	   	        
				   }while(ripInt==true);	  		
			    }
			   tot=tot-a.Due; 
		    }
		  if(s==3)
		     {
		      ripetere=false;
			  ripInt=false;	
		      for(int p=0;p<a.Due;p++)
			     { 
			      do
				   {
				      do
					   {	
			     	     cout<<"In che direzione va inserita la nave?";
			     	     cout<<"[1] Sinistra, [2] Destra, [3] Verso l'alto, [4] Verso il basso\n";
			     	     cin>>direzione;
			             cout<<"inserire la Riga di partenza:";
                         cin>>r;
                         cout<<"Inserire la Colonna di partenza:";
                         cin>>cc;
                         c=convertitore(cc);
                         if(c>10 || r>10)
                            {
                            	cout<<"Il numero inserito e' troppo grande! Reinserire\n";
                            	ripetere=true;
						    }	
					     else
					        {
					        	ripetere=false;
						    }   
                       }while(ripetere==true);
                    m[r-1][c]=1;
                    if(direzione==1 && c<=1)
                       {
                       	cout<<"La nave esce dalla mappa! Reinserire\n";
                       	ripInt=true;
					   }
					if(direzione==1 && c>=2)
					   {
					   	m[r-1][c-1]=1;
					   	m[r-1][c-2]=1;
					   }       
					if(direzione==2 && c>8 )
					   {
					    cout<<"La nave esce dalla mappa! Reinserire\n";	
					    ripInt=true;
				       }
					if(direzione==2 && c<=9)
					   {
					   	m[r-1][c+1]=1;
					   	m[r-1][c+2]=1;
					   }       
					if(direzione==3 && r<=2)
					   {
					    cout<<"La nave esce dalla mappa! Reinserire\n";
						ripInt=true;
					   }
					if(direzione==3 && r>=2)
					   {
					   	m[r-2][c]=1;
					   	m[r-3][c]=1;
					   }   
					if(direzione==4 && r>=8)
					   {
					    cout<<"La nave esce dalla mappa! Reinserire\n";
						ripInt=true;	
					   }
					if(direzione==4 && r<=8)
					   {
					   	m[r][c]=1;
					   	m[r+1][c]=1;
					   }   	   	        
				   }while(ripInt==true);
	  	
			 }
			 tot=tot-a.Tre; 
	     }
		  if(s==4)
		     {
		      ripetere=false;
			  ripInt=false;			     	
		      for(int q=0;q<a.Due;q++)
			     { 
			      do
				   {
				      do
					   {	
			     	     cout<<"In che direzione va inserita la nave?";
			     	     cout<<"[1] Sinistra, [2] Destra, [3] Verso l'alto, [4] Verso il basso";
			     	     cin>>direzione;
			             cout<<"inserire la Riga di partenza:";
                         cin>>r;
                         cout<<"Inserire la Colonna di partenza:";
                         cin>>cc;
                         c=convertitore(cc);
                         if(c>10 || r>10)
                            {
                            	cout<<"Il numero inserito e' troppo grande! Reinserire\n";
                            	ripetere=true;
						    }	
					     else
					        {
					        	ripetere=false;
						    }   
                       }while(ripetere==true);
                    m[r-1][c]=1;
                    if(direzione==1 && c<=0)
                       {
                       	cout<<"La nave esce dalla mappa! Reinserire\n";
                       	ripInt=true;
					   }
					if(direzione==1 && c>=2)
					   {
					   	m[r-1][c-1]=1;
					   	m[r-1][c-2]=1;
					   	m[r-1][c-3]=1;
					   }       
					if(direzione==2 && c>9 )
					   {
					    cout<<"La nave esce dalla mappa! Reinserire\n";	
					    ripInt=true;
				       }
					if(direzione==2 && c<=10)
					   {
					   	m[r-1][c+1]=1;
					   	m[r-1][c+2]=1;
					   	m[r-1][c+3]=1;
					   }       
					if(direzione==3 && r<=0)
					   {
					    cout<<"La nave esce dalla mappa! Reinserire\n";
						ripInt=true;
					   }
					if(direzione==3 && r>=2)
					   {
					   	m[r-2][c]=1;
					   	m[r-3][c]=1;
					   	m[r-4][c]=1;
					   }   
					if(direzione==4 && r>=9)
					   {
					    cout<<"La nave esce dalla mappa! Reinserire\n";
						ripInt=true;	
					   }
					if(direzione==4 && r<=9)
					   {
					   	m[r][c]=1;
					   	m[r+1][c]=1;
					   	m[r+2][c]=1;
					   }   	   	        
				   }while(ripInt==true);	  		
		     }
		   	tot=tot-a.Quattro;  
	    }
		   if(s>4)
             {
             	cout<<"Nella battaglia navale non esistono navi piu' grandi di 4 blocchi, riprovare\n";
			 }
	   }
    }while(tot!=0);
	   return;
    }           
 
void campo(int cA[10][10])
     {
     int r=0,c,i,num=1;
     char lettera='A';
     cout<<"\t"; 
     for(i=0;i<10;i++)
         {
          cout<<lettera<<"\t";
          lettera++;           
         } 
     cout<<"\n\n";       
     for(r=0;r<10;r++)
         {  
           cout<<num;
           num++;
           for(c=0;c<10;c++)
              {	
               cout<<"\t";
               cout<<cA[r][c];
               }
           cout<<"\n"<<"\n";    
          }
          return;                                  
     } 

void battaglia(int tot,int m[10][10],int n[10][10],int mU[10][10],int nU[10][10]) //non carica in maniera corretta le sparate nel campo delle sparate, quindi non riesce a dare un vincitore
     {
        int c,r,i;
        int p=tot,s=tot;
        fflush(stdin);
        do
          {
          	fflush(stdin);
		    cout<<"Comandante Uno:\n";
            cout<<"Dove si desidera colpire?\n";
            cout<<"Riga: ";
            scanf("%d",&r);
            cout<<"Colonna: ";
            scanf("%d",&c);
            fflush(stdin);
	        m[r-1][c]=1;
     	      if(n[r-1][c]==1)
		        {
		  	      p--;
		        }
		    cout<<"Visualizzazione del campo del comandante uno:\n ";
			campo(mU);
			cout<<"\nVisualizzazione delle sparate del comandante uno:\n";
			campo(m);
			cout<<"\nVisualizzazione delle sparate del comandante due:\n";
			campo(n);				
			system("pause");
			system("cls");    
		    fflush(stdin);    
            cout<<"Comandante Due:\n";
            cout<<"Dove si desidera colpire?\n";
            cout<<"Riga: ";
            scanf("%d",&r);
            cout<<"Colonna: ";
            scanf("%d",&c);
	        n[r-1][c]=1;
		      if(m[r-1][c]==1)
		        {
		  	     s--;
		        }
		    cout<<"visualizzazione del campo del comandante due:\n ";
			campo(nU);
			cout<<"\nVisualizzazione delle sparate del comandante due:\n";
			campo(n);
			cout<<"\nVisualizzazione delle sparate del comandante uno:\n";
			campo(m);			
			system("pause");
			system("cls");				 
	      }while(p>=0||s>=0);
	    if(p==0)
		   {
		   	system("cls");
		   	cout<<"Complimenti al primo comandante! Lei e la sua flotta avete vinto la guerra!\n";
		   }
		if(s==0)
		   {
		   	system("cls");
		   	cout<<"Complimenti al secondo comandante! Lei e la sua flotta avete vinto la guerra!\n";
		   } 
		if(s==0 && p==0)
		   {
		    system("cls");
			cout<<"La battaglia e' finita in parita', complimenti ad entrambi i comandanti! La guerra non finisce mai..";	
		   }   
      return;
	 }	     

void numeroNavi(navi &a)
     {
       cout<<"Quante navi da 1 si vogliono mettere? ";
	   cin>>a.Uno;
	   cout<<"Quante navi da 2 si vogliono mettere? ";
	   cin>>a.Due;
	   cout<<"Quante navi da 3 si vogliono mettere? ";
	   cin>>a.Tre;
	   cout<<"Quante navi da 4 si vogliono mettere? ";
	   cin>>a.Quattro;
       return;
	 } 
	                                     

int main()
{
   //dichiarazione delle variabili
   int const DIM=10;
   int campoUno[DIM][DIM];
   int campoDue[DIM][DIM];
   int sparateUno[DIM][DIM];
   int sparateDue[DIM][DIM];
   int scelta;
   bool ag=false,aga=false;
   struct navi numero;
   int totNavi=0;
   
   //inizializzazione dei campi di gioco
   svuotaMatrice(campoUno);
   svuotaMatrice(campoDue);
   svuotaMatrice(sparateUno);
   svuotaMatrice(sparateDue);  

   introduzione();  //Introduzione al gioco
   do              //do-while che permette la ripetizione del programma
   {
   menu();         //Primo menu di scelta per cosa fare
   cin>>scelta;
   switch(scelta)
         {
          case 0:  //uscita dal programma
               {
                 system("cls");
                 cout<<"Va bene comandanti, ma prima o poi dovrete affrontare il fato!\n";
                 ag=false;   //variabile booleana utilizzata per i cicli do-while
                 aga=false;
                 break;             
               }                     
          case 1:  //sapere le regole del gioco
               {
                 system("cls");
                 regole();
                 ag=true;
                 system("pause");
                 system("cls");
                 break;                                    
               }
          case 2:   //primo menù annidato per iniziare il gioco
               {
               	do
               	 {
                 system("cls");
                 preparazione();        //azioni prepartita
                 cin>>scelta;                                            
                 switch(scelta)
                       {
                        case 0:  //uscita dal programma
                             {
                               system("cls");
                               cout<<"Va bene comandanti, ma prima o poi dovrete affrontare il fato!\n";
                               ag=false;
                               aga=false;
                               break;                                                                      
                             }                                                   
                        case 1:   //Inserimento delle flotte da parte dei due giocatori
                             {
                               system("cls");	
							   numeroNavi(numero);
							   totNavi=totNavi+numero.Uno+numero.Due+numero.Tre+numero.Quattro;
							   cout<<"\nOra,a turno, i comandanti dovranno disporre le proprie flotte\n";
							   system("pause");	
                               system("cls");
                               cout<<"\n\tComandante uno:\n";
                               inserimentoFlotte(campoUno,totNavi,numero);    
                               cout<<"\n\tFlotta del comandante uno:\n\n";
                               campo(campoUno);
                               cout<<"\n";
                               system("pause");
                               system("cls");
                               cout<<"\n\tComandante due:\n";
                               inserimentoFlotte(campoDue,totNavi,numero); 
                               cout<<"\n\tFlotta del comandante due:\n\n";
                               campo(campoDue);
                               cout<<"\n";
                               system("pause");
                               system("cls");
                               aga=true;
                               break;                                                    
                             }
                        case 2:
                             {
                               system("cls");
                               aga=true;
                               cout<<"Prima di tutto, reinserire il numero di navi da utilizzare:\n";
                               numeroNavi(numero);
                               totNavi=totNavi+numero.Uno+numero.Due+numero.Tre+numero.Quattro;
                               system("pause");
                               system("cls");
                               riposizionamento();  //menu per il riposizionamento delle flotte
                               cin>>scelta;
                               switch(scelta)
                                     {
                                     	case 0:   //uscita dal programma
                                     		{
                                     		 cout<<"Va bene comandanti!";  
                                     		 break;
											}
                                     	case 1:   //inserimento della flotta da parte di un solo comandante
                                     		{	
                                     		 svuotaMatrice(campoUno);	
                                             inserimentoFlotte(campoUno,totNavi,numero); 
                                             aga=true;
											 break;                                     		    	
											}
                                     	case 2:  //inserimento della flotta da parte di un solo comandante
                                     		{	
                                     		 svuotaMatrice(campoDue);	
                                             inserimentoFlotte(campoDue,totNavi,numero);  
											 aga=true;                                   			
                                     		 break;	
											}
                                     	case 3:   //inserimento della flotta da parte di entrambi i comandanti
                                     		{
                                     		 svuotaMatrice(campoUno);	
                                     		 svuotaMatrice(campoDue);	
                                     		 cout<<"\nPrimo comandante:\n";
                                             inserimentoFlotte(campoUno,totNavi,numero); 											  	
                                     		 system("pause");
											 system("cls");
											 cout<<"\nOra il secondo comandante: \n";
                                             inserimentoFlotte(campoDue,totNavi,numero); 											  	
                                     		 system("pause");
											 system("cls");
											 aga=true;
											 break;											  	
											}
									 }
                               break;                                                           
                             }	   
                        case 3:  //la battaglia vera e propria
                             {
                               system("cls");
                               battaglia(totNavi,sparateUno,sparateDue,campoUno,campoDue);
                               aga=false;
                               break;                                                                 
                             }	                                                                                                                               
                       }
			     }while(aga==true);                                          
               } 
		break;	                                                                                     
         }
    }while(ag==true);
    
    system("pause");
    return 0;
}   
