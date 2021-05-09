/*******************************************************************************
Autor: Thiago Cardozo de Jesus
Componente Curricular: Algoritmos I
Concluido em: 22/09/2018
Declaro que este c�digo foi elaborado por mim de forma individual e n�o cont�m nenhum
trecho de c�digo de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e p�ginas ou documentos eletr�nicos da Internet. Qualquer trecho de c�digo
de outra autoria que n�o a minha est� destacado com uma cita��o para o autor e a fonte
do c�digo, e estou ciente que estes trechos n�o ser�o considerados para fins de avalia��o.
******************************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#define PESO 3

int escolhaidade,escolhacurso,escolha=0,repetir=0,pesquisa=0,escolhasexo=0; //As v�riaveis desta linha, s�o basicamente feitas para o receber a informa��o passada pelo usu�rio e envi�-las para outras vari�veis,geralmente associadas a bloco de condi��o//
int sexoM=0,sexoF=0,idade18=0,idade21=0,idade24=0,cursoeng=0,cursomed=0,cursohist=0,cursolet=0,totalP;//As v�riaveis desta linha, s�o, respectivamente, contadores para:O sexo do participante, as 3 faixas et�rias, as 4 op��es de curso e o total de participantes
 /*O Bloco de vari�veis a seguir, � relacionada ao calculo de frequencia relativa e absoluta dos n�veis de concord�ncia de cada quest�o
 Tais vari�veis est�o indentificadas em (a[n][niveldeconcordancia]) onde: an � a n�mero da afirma��o,ex: a1= afirma��o 1, a2= afirma��o2.
 E o n�vei de concordancia est� identificado como:discordoT para discordo totalmente,discordo para discordo,discordoP para discordo Parcialmente,concordoP para
 concordo parcialmente,concordo para concordo e concordoT para concordo totalmente*/
int a1discordoT=0,a1discordo=0,a1discordoP=0,a1concordoP=0,a1concordo=0,a1concordoT=0,a2discordoT=0,a2discordo=0,a2discordoP=0,a2concordoP=0,a2concordo=0,a2concordoT=0;
int a3discordoT=0,a3discordo=0,a3discordoP=0,a3concordoP=0,a3concordo=0,a3concordoT=0,a4discordoT=0,a4discordo=0,a4discordoP=0,a4concordoP=0,a4concordo=0,a4concordoT=0;
int a5discordoT=0,a5discordo=0,a5discordoP=0,a5concordoP=0,a5concordo=0,a5concordoT=0,a6discordoT=0,a6discordo=0,a6discordoP=0,a6concordoP=0,a6concordo=0,a6concordoT=0;
int a7discordoT=0,a7discordo=0,a7discordoP=0,a7concordoP=0,a7concordo=0,a7concordoT=0,a8discordoT=0,a8discordo=0,a8discordoP=0,a8concordoP=0,a8concordo=0,a8concordoT=0;
int a9discordoT=0,a9discordo=0,a9discordoP=0,a9concordoP=0,a9concordo=0,a9concordoT=0,a10discordoT=0,a10discordo=0,a10discordoP=0,a10concordoP=0,a10concordo=0,a10concordoT=0;
int a11discordoT=0,a11discordo=0,a11discordoP=0,a11concordoP=0,a11concordo=0,a11concordoT=0,a12discordoT=0,a12discordo=0,a12discordoP=0,a12concordoP=0,a12concordo=0,a12concordoT=0;
int a13discordoT=0,a13discordo=0,a13discordoP=0,a13concordoP=0,a13concordo=0,a13concordoT=0,a14discordoT=0,a14discordo=0,a14discordoP=0,a14concordoP=0,a14concordo=0,a14concordoT=0;
int a15discordoT=0,a15discordo=0,a15discordoP=0,a15concordoP=0,a15concordo=0,a15concordoT=0,a16discordoT=0,a16discordo=0,a16discordoP=0,a16concordoP=0,a16concordo=0,a16concordoT=0;
int a17discordoT=0,a17discordo=0,a17discordoP=0,a17concordoP=0,a17concordo=0,a17concordoT=0;
/*O Bloco a seguir consiste em v�riaveis respons�veis em guardar as soma dos n�veis de concordancia para cada quest�o da enquete, ser�o ultilizadas no c�lculo
da frequencia relativa.Elas est�o identificadas em a[n]resultadoconcordancia, onde n � o n�mero da afirma��o a qual a vari�vel � referente */
float a1resultadoconcordancia,a2resultadoconcordancia,a3resultadoconcordancia,a4resultadoconcordancia,a5resultadoconcordancia,a6resultadoconcordancia,a7resultadoconcordancia;
float a8resultadoconcordancia,a9resultadoconcordancia,a10resultadoconcordancia,a11resultadoconcordancia,a12resultadoconcordancia,a13resultadoconcordancia,a14resultadoconcordancia;
float a15resultadoconcordancia,a16resultadoconcordancia,a17resultadoconcordancia;
/*A vari�vel com a palavra "score1" � referente ao escore da primeira categoria,Submiss�o � autoridade.h� algumas v�ria��es da mesma,quanto a sua especificidade: 
ex:score1cursoeng (escore da 1� categoria para o curso de engenharia),score1sexoM (escore da 1� categoria para o sexo masculino)
A mesma l�gica se aplica as vari�veis score2,referente � categoria Agressividade autorit�ria, e score3,referente � categoria Convencionalismo.*/
float score1=0,score2=0,score3=0,indicegeral=0,score1sexoM=0,score1idade18=0,score1cursoeng=0,score2sexoM=0,score2idade18=0,score2cursoeng=0,score3sexoM=0,score3idade18=0,score3cursoeng=0;
float score1cursomed=0,score2cursomed=0,score3cursomed=0,score1cursohist=0,score2cursohist=0,score3cursohist=0,score1cursolet=0,score2cursolet=0,score3cursolet=0,score1idade21=0;
float score2idade21=0,score3idade21=0,score1idade24=0,score2idade24=0,score3idade24=0,score1sexoF=0,score2sexoF=0,score3sexoF=0,totalscore1=0,totalscore2=0,totalscore3=0;
/*A pr�xima linha de c�digo � referente,respectivamente, �s v�riaveis relacionadas a: soma dos contadores de n�vel de concordancia, a acumula��o dos 3 escores das categorias
e aos indices de propens�o para cada op��o de sexo, */
float resultadoconcordancia=0,score1total=0,score2total=0,score3total=0,indicetotalP=0,indicesexoM=0,indicesexoF=0,indiceidade18=0,indiceidade21=0,indiceidade24=0,indicecursoeng=0,indicecursomed=0,indicecursohist=0,indicecursolet=0;
int main(){
	system("color C");
	do{
		score1=0;
		score2=0;
		score3=0;
		setlocale(LC_ALL, "Portuguese");
		printf("A seguir ser�o mostrada algumas afirma��es.\nResponda-a ,com o n�mero correspondente �s formas de respostas predefinidas, aquela que mais se adequa � sua opini�o\n\nTecle:\n[1]Para responder: Discordo totalmente\n[2]Para responder: Discordo \n[3]Para responder: Discordo parcialmente\n[4]Para responder: Concordo parcialmente\n[5]Para responder: Concordo\n[6]Para responder: Concordo Totalmente");
		do{
			printf("\n\nAfirma��o 1:O que este pa�s necessita, principalmente,antes das leis ou planos pol�ticos, � de alguns lideres valentes, incans�veis e dedicados em quem o povo possa depositar a sua f�\nResposta:  ");
			scanf("%d",&escolha);
			fflush(stdin);
		    switch(escolha){
		        case 1:
		        	a1discordoT++;
		        	score1+=escolha; 
					break;
				case 2:
					a1discordo++;
		        	score1+=escolha;
		        	break;
		        case 3:
		        	a1discordoP++;
		        	score1+=escolha;
		        	break;
		        case 4:
		        	a1concordoP++;
		        	score1+=escolha;
		        	break;
		        case 5:
		        	a1concordo++;
		        	score1+=escolha;
		        	break;
		        case 6:
		        	a1concordoT++;
		        	score1+=escolha;
		        	break;
		        default:
		        	printf("\nResposta inv�lida.Tente uma tecla v�lida\n\n\n");
		        	break;
		    	}	
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirma��o 2:A obedi�ncia e o respeito � autoridade s�o as principais virtudes que devemos ensinar as nossas crian�as\nResposta: ");
			scanf("%d",&escolha);
			fflush(stdin);
			switch(escolha){
		        case 1:
		        	a2discordoT++;
		        	score1+=escolha;
					break;
				case 2:
					a2discordo++;
		        	score1+=escolha;
		        	break;
		        case 3:
		        	a2discordoP++;
		        	score1+=escolha;
		        	break;
		        case 4:
		        	a2concordoP++;
		        	score1+=escolha;
		        	break;
		        case 5:
		        	a2concordo++;
		        	score1+=escolha;
		        	break;
		        case 6:
		        	a2concordoT++;
		        	score1+=escolha;
		        	break;
				default:
					printf("\nResposta inv�lida.Tente uma tecla v�lida\n\n\n");							
				}		
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirma��o 3:N�o h� nada pior do que uma pessoa que n�o sente profundo amor, gratid�o e respeito por seus pais\nResposta: ");
			scanf("%d",&escolha);
			fflush(stdin);
		        //adicionar as variaveis correspondentes//PRIMEIRO ESCORE
			switch(escolha){
		        case 1:
		        	a3discordoT++;
		        	score1+=escolha;
					break;
				case 2:
					a3discordo++;
		        	score1+=escolha;
		        	break;
		        case 3:
		        	a3discordoP++;
		        	score1+=escolha;
		        	break;
		        case 4:
		        	a3concordoP++;
		        	score1+=escolha;
		        	break;
		        case 5:
		        	a3concordo++;
		        	score1+=escolha;
		        	break;
		        case 6:
		        	a3concordoT++;
		        	score1+=escolha;
		        	break;
				default:
					printf("\nResposta inv�lida.Tente uma tecla v�lida\n\n\n");								
				}			
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirma��o 4:Nenhuma pessoa decente,normal e em seu s�o ju�zo pensaria em ofender um amigo ou parente pr�ximo\nResposta: ");
			scanf("%d",&escolha);
			fflush(stdin);
			switch(escolha){
		        case 1:
		        	a4discordoT++;
		        	score1+=escolha;
					break;
				case 2:
					a4discordo++;
		        	score1+=escolha;
		        	break;
		        case 3:
		        	a4discordoP++;
		        	score1+=escolha;
		        	break;
		        case 4:
		        	a4concordoP++;
		        	score1+=escolha;
		        	break;
		        case 5:
		        	a4concordo++;
		        	score1+=escolha;
		        	break;
		        case 6:
		        	a4concordoT++;
		        	score1+=escolha;
		        	break;
				default:
					printf("\nResposta inv�lida.Tente uma tecla v�lida\n\n\n");								
				}		
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirma��o 5:O policial � um guerreiro de Deus para impor a ordem e proteger as pessoas de bem\nResposta: ");
			scanf("%d",&escolha);
			fflush(stdin);
		    switch(escolha){
		        case 1:
		        	a5discordoT++;
		        	score1+=escolha;
					break;
				case 2:
					a5discordo++;
		        	score1+=escolha;
		        	break;
		        case 3:
		        	a5discordoP++;
		        	score1+=escolha;
		        	break;
		        case 4:
		        	a5concordoP++;
		        	score1+=escolha;
		        	break;
		        case 5:
		        	a5concordo++;
		        	score1+=escolha;
		        	break;
		        case 6:
		        	a5concordoT++;
		        	score1+=escolha;
		        	break;
				default:
					printf("\nResposta inv�lida.Tente uma tecla v�lida\n\n\n");				
				}	
		}while (escolha<=0 || escolha>=7);
		escolha=0;
		do{
			printf("\n\nAfirma��o 6:A maioria de nossos problemas sociais estaria resolvida se pud�ssemos nos livrar das pessoas imorais,dos marginais e dos pervertidos\nResposta: ");
			scanf("%d",&escolha);
			fflush(stdin);
		    switch(escolha){
		        case 1:
		        	a6discordoT++;
		        	score2+=escolha;
					break;
				case 2:
					a6discordo++;
		        	score2+=escolha;
		        	break;
		        case 3:
		        	a6discordoP++;
		        	score2+=escolha;
		        	break;
		        case 4:
		        	a6concordoP++;
		        	score2+=escolha;
		        	break;
		        case 5:
		        	a6concordo++;
		        	score2+=escolha;
		        	break;
		        case 6:
		        	a6concordoT++;
		        	score2+=escolha;
		        	break;
				default:
					printf("\nResposta inv�lida.Tente uma tecla v�lida\n\n\n");				
				}						
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirma��o 7:Se fal�ssemos menos e trabalh�ssemos mais,todos estar�amos melhor\nResposta: ");
			scanf("%d",&escolha);
			fflush(stdin);
		    switch(escolha){
		        case 1:
		        	a7discordoT++;
		        	score2+=escolha;
					break;
				case 2:
					a7discordo++;
		        	score2+=escolha;
		        	break;
		        case 3:
		        	a7discordoP++;
		        	score2+=escolha;
		        	break;
		        case 4:
		        	a7concordoP++;
		        	score2+=escolha;
		        	break;
		        case 5:
		        	a7concordo++;
		        	score2+=escolha;
		        	break;
		        case 6:
		        	a7concordoT++;
		        	score2+=escolha;
		        	break;
				default:
					printf("\nResposta inv�lida.Tente uma tecla v�lida\n\n\n");	
				}	
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirma��o 8:Deve-se castigar sempre todo insulto � nossa honra \nResposta: ");
			scanf("%d",&escolha);
			fflush(stdin);
		    switch(escolha){
		        case 1:
		        	a8discordoT++;
		        	score2+=escolha;
					break;
				case 2:
					a8discordo++;
		        	score2+=escolha;
		        	break;
		        case 3:
		        	a8discordoP++;
		        	score2+=escolha;
		        	break;
		        case 4:
		        	a8concordoP++;
		        	score2+=escolha;
		        	break;
		        case 5:
		        	a8concordo++;
		        	score2+=escolha;
		        	break;
		        case 6:
		        	a8concordoT++;
		        	score2+=escolha;
		        	break;
				default:
					printf("\nResposta inv�lida.Tente uma tecla v�lida\n\n\n");				
				}										
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirma��o 9:Os crimes sexuais, tais como estupro ou ataques a crian�as merecem mais que pris�o;quem comete esses crimes deveria receber puni��o f�sica publicamente ou receber castigo pior\nResposta: ");
			scanf("%d",&escolha);
			fflush(stdin);
		    switch(escolha){
		        case 1:
		        	a9discordoT++;
		        	score2+=escolha;
					break;
				case 2:
					a9discordo++;
		        	score2+=escolha;
		        	break;
		        case 3:
		        	a9discordoP++;
		        	score2+=escolha;
		        	break;
		        case 4:
		        	a9concordoP++;
		        	score2+=escolha;
		        	break;
		        case 5:
		        	a9concordo++;
		        	score2+=escolha;
		        	break;
		        case 6:
		        	a9concordoT++;
		        	score2+=escolha;
		        	break;
				default:
					printf("\nResposta inv�lida.Tente uma tecla v�lida\n\n\n");				
				}						
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirma��o 10:Os homossexuais s�o quase criminosos e deveriam receber um castigo severo\nResposta: ");
			scanf("%d",&escolha);
			fflush(stdin);
		    switch(escolha){
		        case 1:
		        	a10discordoT++;
		        	score2+=escolha;
					break;
				case 2:
					a10discordo++;
		        	score2+=escolha;
		        	break;
		        case 3:
		        	a10discordoP++;
		        	score2+=escolha;
		        	break;
		        case 4:
		        	a10concordoP++;
		        	score2+=escolha;
		        	break;
		        case 5:
		        	a10concordo++;
		        	score2+=escolha;
		        	break;
		        case 6:
		        	a10concordoT++;
		        	score2+=escolha;
		        	break;
				default:
					printf("\nResposta inv�lida.Tente uma tecla v�lida\n\n\n");				
				}										
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirma��o 11:�s vezes, os jovens t�m ideias rebeldes que,com os anos, dever�o superar para acalmar os seus pensamentos\nResposta: ");
			scanf("%d",&escolha);
			fflush(stdin);
		    switch(escolha){
		        case 1:
		        	a11discordoT++;
		        	score2+=escolha;
					break;
				case 2:
					a11discordo++;
		        	score2+=escolha;
		        	break;
		        case 3:
		        	a11discordoP++;
		        	score2+=escolha;
		        	break;
		        case 4:
		        	a11concordoP++;
		        	score2+=escolha;
		        	break;
		        case 5:
		        	a11concordo++;
		        	score2+=escolha;
		        	break;
		        case 6:
		        	a11concordoT++;
		        	score2+=escolha;
		        	break;
				default:
					printf("\nResposta inv�lida.Tente uma tecla v�lida\n\n\n");				
				}										
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirma��o 12:Hoje em dia, as pessoas se intrometem cada vez mais em assuntos que deveriam ser somente pessoais e privados\nResposta: ");
			scanf("%d",&escolha);
			fflush(stdin);
		    switch(escolha){
		        case 1:
		        	a12discordoT++;
		        	score2+=escolha;
					break;
				case 2:
					a12discordo++;
		        	score2+=escolha;
		        	break;
		        case 3:
		        	a12discordoP++;
		        	score2+=escolha;
		        	break;
		        case 4:
		        	a12concordoP++;
		        	score2+=escolha;
		        	break;
		        case 5:
		        	a12concordo++;
		        	score2+=escolha;
		        	break;
		        case 6:
		        	a12concordoT++;
		        	score2+=escolha;
		        	break;
				default:
					printf("\nResposta inv�lida.Tente uma tecla v�lida\n\n\n");				
				}						
		}while (escolha<=0 || escolha>=7);
		escolha=0;
		do{
			printf("\n\nAfirma��o 13:A ci�ncia tem o seu lugar, mas h� muitas coisas importantes que a mente humana jamais poder� compreender\nResposta: ");
			scanf("%d",&escolha);
			fflush(stdin);
		    switch(escolha){
		        case 1:
		        	a13discordoT++;
		        	score3+=escolha;
					break;
				case 2:
					a13discordo++;
		        	score3+=escolha;
		        	break;
		        case 3:
		        	a13discordoP++;
		        	score3+=escolha;
		        	break;
		        case 4:
		        	a13concordoP++;
		        	score3+=escolha;
		        	break;
		        case 5:
		        	a13concordo++;
		        	score3+=escolha;
		        	break;
		        case 6:
		        	a13concordoT++;
		        	score3+=escolha;
		        	break;
				default:
					printf("\nResposta inv�lida.Tente uma tecla v�lida\n\n\n");				
				}										
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirma��o 14:Os homens podem ser divididos em duas classes definidas:Fortes e Fracos\nResposta: ");
			scanf("%d",&escolha);
			fflush(stdin);
		    switch(escolha){
		        case 1:
		        	a14discordoT++;
		        	score3+=escolha;
					break;
				case 2:
					a14discordo++;
		        	score3+=escolha;
		        	break;
		        case 3:
		        	a14discordoP++;
		        	score3+=escolha;
		        	break;
		        case 4:
		        	a14concordoP++;
		        	score3+=escolha;
		        	break;
		        case 5:
		        	a14concordo++;
		        	score3+=escolha;
		        	break;
		        case 6:
		        	a14concordoT++;
		        	score3+=escolha;
		        	break;
				default:
					printf("\nResposta inv�lida.Tente uma tecla v�lida\n\n\n");				
				}									
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirma��o 15:Um indiv�duo de m�s maneiras,maus costumes e m� educa��o dificilmente pode fazer amizade com pessoas decentes\nResposta: ");
			scanf("%d",&escolha);
			fflush(stdin);
		    switch(escolha){
		        case 1:
		        	a15discordoT++;
		        	score3+=escolha;
					break;
				case 2:
					a15discordo++;
		        	score3+=escolha;
		        	break;
		        case 3:
		        	a15discordoP++;
		        	score3+=escolha;
		        	break;
		        case 4:
		        	a15concordoP++;
		        	score3+=escolha;
		        	break;
		        case 5:
		        	a15concordo++;
		        	score3+=escolha;
		        	break;
		        case 6:
		        	a15concordoT++;
		        	score3+=escolha;
		        	break;
				default:
					printf("\nResposta inv�lida.Tente uma tecla v�lida\n\n\n");				
				}									
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirma��o 16:Todos devemos ter f� absoluta em um poder sobrenatural,cujas decis�es devemos acatar\nResposta: ");
			scanf("%d",&escolha);
			fflush(stdin);
		    switch(escolha){
		        case 1:
		        	a16discordoT++;
		        	score3+=escolha;
					break;
				case 2:
					a16discordo++;
		        	score3+=escolha;
		        	break;
		        case 3:
		        	a16discordoP++;
		        	score3+=escolha;
		        	break;
		        case 4:
		        	a16concordoP++;
		        	score3+=escolha;
		        	break;
		        case 5:
		        	a16concordo++;
		        	score3+=escolha;
		        	break;
		        case 6:
		        	a16concordoT++;
		        	score3+=escolha;
		        	break;
				default:
					printf("\nResposta inv�lida.Tente uma tecla v�lida\n\n\n");				
				}									
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirma��o 17:Pobreza � consequencia de falta de vontade de querer trabalhar\nResposta: ");
			scanf("%d",&escolha);
			fflush(stdin);
		    switch(escolha){
		        case 1:
		        	a17discordoT++;
		        	score3+=escolha;
					break;
				case 2:
					a17discordo++;
		        	score3+=escolha;
		        	break;
		        case 3:
		        	a17discordoP++;
		        	score3+=escolha;
		        	break;
		        case 4:
		        	a17concordoP++;
		        	score3+=escolha;
		        	break;
		        case 5:
		        	a17concordo++;
		        	score3+=escolha;
		        	break;
		        case 6:
		        	a17concordoT++;
		        	score3+=escolha;
		        	break;
				default:
					printf("\nResposta inv�lida.Tente uma tecla v�lida\n\n\n");				
				}				
		}while (escolha<=0 || escolha>=7);
		/* */
		a1resultadoconcordancia=a1discordoT+a1discordo+a1discordoP+a1concordoP+a1concordo+a1concordoT;
		a2resultadoconcordancia=a2discordoT+a2discordo+a2discordoP+a2concordoP+a2concordo+a2concordoT;
		a3resultadoconcordancia=a3discordoT+a3discordo+a3discordoP+a3concordoP+a3concordo+a3concordoT;
		a4resultadoconcordancia=a4discordoT+a4discordo+a4discordoP+a4concordoP+a4concordo+a4concordoT;
		a5resultadoconcordancia=a5discordoT+a5discordo+a5discordoP+a5concordoP+a5concordo+a5concordoT;
		a6resultadoconcordancia=a6discordoT+a6discordo+a6discordoP+a6concordoP+a6concordo+a6concordoT;
		a7resultadoconcordancia=a7discordoT+a7discordo+a7discordoP+a7concordoP+a7concordo+a7concordoT;
		a8resultadoconcordancia=a8discordoT+a8discordo+a8discordoP+a8concordoP+a8concordo+a8concordoT;
		a9resultadoconcordancia=a9discordoT+a9discordo+a9discordoP+a9concordoP+a9concordo+a9concordoT;
		a10resultadoconcordancia=a10discordoT+a10discordo+a10discordoP+a10concordoP+a10concordo+a10concordoT;
		a11resultadoconcordancia=a11discordoT+a11discordo+a11discordoP+a11concordoP+a11concordo+a11concordoT;
		a12resultadoconcordancia=a12discordoT+a12discordo+a12discordoP+a12concordoP+a12concordo+a12concordoT;
		a13resultadoconcordancia=a13discordoT+a13discordo+a13discordoP+a13concordoP+a13concordo+a13concordoT;
		a14resultadoconcordancia=a14discordoT+a14discordo+a14discordoP+a14concordoP+a14concordo+a14concordoT;
		a15resultadoconcordancia=a15discordoT+a15discordo+a15discordoP+a15concordoP+a15concordo+a15concordoT;
		a16resultadoconcordancia=a16discordoT+a16discordo+a16discordoP+a16concordoP+a16concordo+a16concordoT;
		a17resultadoconcordancia=a17discordoT+a17discordo+a17discordoP+a17concordoP+a17concordo+a17concordoT;
		system("pause");
		system("cls");
		do{
		printf ("Digite o n�mero dentre as op��es que corresponde ao seu sexo:\n\n[1]Homem\n[2]Mulher\nResposta: ");
		scanf("%d",&escolhasexo);
		fflush(stdin);
		if (escolhasexo==1){
			sexoM+=1;
			score1sexoM+=score1;
			score2sexoM+=score2;
			score3sexoM+=score3;
		}
		else if (escolhasexo==2){
			sexoF+=1;
			score1sexoF+=score1;
			score2sexoF+=score2;
			score3sexoF+=score3;
		}
		else
			printf("escolha inv�lida\n\n");
	}while(escolhasexo<=0||escolhasexo>=3);
	do {
		printf("Digite o n�mero dentre op��es que corresponde � sua idade:\n\n[1] 18 anos a 20 anos\n[2] 21 anos a 23 anos\n[3] Acima de 23 anos\nResposta: ");
		scanf("%d",&escolhaidade);
		fflush(stdin);
		if(escolhaidade==1){
			idade18++;
			score1idade18+=score1;
			score2idade18+=score2;
			score3idade18+=score3;
		}
		else if (escolhaidade==2){
			idade21++;
			score1idade21+=score1;
			score2idade21+=score2;
			score3idade21+=score3;
		}	
		else if (escolhaidade==3){
			idade24++;
			score1idade24=score1;
			score2idade24=score2;
			score3idade24=score3;
		}
		else
			printf("Escolha inv�lida\n\n");
	}while (escolhaidade>=4 || escolhaidade<=0);
	do {
		printf("Digite o n�mero dentre as op��es que corresponde � seu curso\n\n[1] Engenharia Civil\n[2] Medicina\n[3] Hist�ria\n[4] Letras Vern�culas\nResposta: ");
		scanf("%d",&escolhacurso);
		fflush(stdin);
		if (escolhacurso==1){
			cursoeng+=1;							
			score1cursoeng+=score1;							
			score2cursoeng+=score2;		
			score3cursoeng+=score3;			
		}
		else if (escolhacurso==2){
			cursomed+=1;							
			score1cursomed+=score1;							
			score2cursomed+=score2;							
			score3cursomed+=score3;
		}
		else if (escolhacurso==3){
			cursohist=1;
			score1cursohist+=score1;
			score2cursohist+=score2;
			score3cursohist+=score3;
		}
		else if (escolhacurso==4){
			cursolet+=1;
			score1cursolet+=score1;							
			score2cursolet+=score2;							
			score3cursolet+=score3;
		}
		else
		printf("Escolha inv�lida\n\n");
	}while (escolhacurso>=5 || escolhacurso<=0);
	totalP=sexoM+sexoF;
	score1total+=score1;
	score2total+=score2;
	score3total+=score3;
	indicetotalP=(((((score1total/5)+(score2total/7)+(score3total/5))/totalP)*10)/(6*3));
	indicesexoM=(((((score1sexoM/5)+(score2sexoM/7)+(score3sexoM/5))/sexoM)*10)/(6*3));
	indicesexoF=(((((score1sexoF/5)+(score2sexoF/7)+(score3sexoF/5))/sexoF)*10)/(6*3));
	indiceidade18=(((((score1idade18/5)+(score2idade18/7)+(score3idade18/5))/idade18)*10)/(6*3));
	indiceidade21=(((((score1idade21/5)+(score2idade21/7)+(score3idade21/5))/idade21)*10)/(6*3));
	indiceidade24=(((((score1idade24/5)+(score2idade24/7)+(score3idade24/5))/idade24)*10)/(6*3));
	indicecursoeng=(((((score1cursoeng/5)+(score2cursoeng/7)+(score3cursoeng/5))/cursoeng)*10)/(6*3));
	indicecursomed=(((((score1cursomed/5)+(score2cursomed/7)+(score3cursomed/5))/cursomed)*10)/(6*3));
	indicecursohist=(((((score1cursohist/5)+(score2cursohist/7)+(score3cursohist/5))/cursohist)*10)/(6*3));
	indicecursolet=(((((score1cursolet/5)+(score2cursolet/7)+(score3cursolet/5))/cursolet)*10)/(6*3));
	printf("Se deseja repetir o question�rio digite [1]: ");
	scanf("%d",&repetir);
	system("cls");
	}while(repetir==1);
	printf("Total de entrevistados: %d",totalP);
	printf("\n\n\nTotal de entrevistados por sexo:\n\nFeminino: %d\nMasculino: %d",sexoF,sexoM);
	printf("\n\n\nTotal de entrevistados por faixa et�ria:\n\n18 a 20 anos: %d\n21 a 23 anos: %d\n24 anos ou acima: %d",idade18,idade21,idade24);
	printf("\n\n\nTotal de entrevistados por curso\n\nEngenharia Civil: %d\nMedicina: %d\nHist�ria: %d\nLetras Vern�culas: %d\n\n\n",cursoeng,cursomed,cursohist,cursolet);
	system("pause");
	system("cls");
	printf("\n\n\nESCORE E INDICE GERAL DE TODOS OS PARTICIPANTES\n\n\n");
	system("pause");
	system("cls"); //TRATAMENTO DE ERROS
	printf("\nESCORE DA CATEGORIA 'SUBMISS�O � AUTORIDADE'\n\n%.2f\n\n\n ESCORE DA CATEGORIA 'AGRESSIVIDADE AUTORIT�RIA'\n\n%.2f\n\n\nESCORE DA CATEGORIA 'CONVENCIONALISMO'\n\n%.2f\n\n\nINDICE DE PROPENS�O AO AUTORITARISMO\n(Quanto mais pr�ximo de 10 mais propenso ao autoritarismo)\n%.2f\n\n",(score1total/5)/(totalP),(score2total/7)/(totalP),(score3total/5)/(totalP),indicetotalP);
	system("pause");
	system("cls");
	printf("\n\n\nESCORE E INDICE GERAL POR FAIXA ET�RIA\n\n\n");
	system("pause");
	system("cls");
	printf("\nESCORE DA CATEGORIA 'SUBMISS�O � AUTORIDADE'\n\nEntre 18 a 20 anos: %.2f\nEntre 21 a 23 anos: %.2f\nAcima de 24 anos: %.2f\n\n\nESCORE DA CATEGORIA 'AGRESSIVIDADE AUTORIT�RIA'\n\nEntre 18 a 20 anos: %.2f\nEntre 21 a 23 anos: %.2f\nAcima de 24 anos: %.2f\n\n\nESCORE DA CATEGORIA 'CONVENCIONALISMO'\n\nEntre 18 a 20 anos: %.2f\nEntre 21 a 23 anos: %.2f\nAcima de 24 anos: %f\n\nINDICE DE PROPENS�O AO AUTORITARISMO\n(Quanto mais pr�ximo de 10 mais propenso ao autoritarismo)\n\nEntre 18 a 20 anos: %.2f\nEntre21 a 23 anos: %.2f\nAcima de 24 anos: %.2f\n",(score1idade18/5)/(idade18),(score1idade21/5)/(idade21),(score1idade24/5)/(idade24),(score2idade18/7)/(idade18),(score2idade21/7)/(idade21),(score2idade24/7)/(idade24),(score3idade18/5)/(idade18),(score3idade21/5)/(idade21),(score3idade24/5)/(idade24),indiceidade18,indiceidade21,indiceidade24);
	system("pause");
	system("cls");
	printf("\n\n\nESCORE E INDICE GERAL POR SEXO\n\n\n");
	system("pause");
	system("cls");
	printf("\nESCORE DA CATEGORIA 'SUBMISS�O � AUTORIDADE'\n\nEntre o Sexo Masculino: %.2f\nEntre o Sexo Feminino: %.2f\n\n\nESCORE DA CATEGORIA 'AGRESSIVIDADE AUTORIT�RIA'\n\nEntre o Sexo Masculino: %.2f\n\Entre o Sexo Feminino: %.2f\n\n\nESCORE DA CATEGORIA 'CONVENCIONALISMO'\n\nEntre o Sexo Masculino: %.2f\nEntre o Sexo Feminino: %.2f\n\n\nINDICE DE PROPENS�O AO AUTORITARISMO\n(Quanto mais pr�ximo de 10 mais propenso ao autoritarismo)\n\nEntre o sexo Masculino: %.2f\nEntre o sexo Feminino: %.2f\n\n",(score1sexoM/5)/(sexoM),(score1sexoF/5)/(sexoF),(score2sexoM/7)/(sexoM),(score2sexoF/7)/(sexoF),(score3sexoM/5)/(sexoM),(score3sexoF/5)/(sexoF),indicesexoM,indicesexoF);
	system("pause");
	system("cls");
	printf("\n\n\nESCORE E INDICE GERAL POR CURSO\n\n\n");
	system("pause");
	system("cls");
	printf("\nESCORE DA CATEGORIA 'SUBMISS�O � AUTORIDADE'\n\nEntre o curso de Engenharia Civil: %.2f\nEntre o curso de Medicina: %.2f\nEntre o curso de Hist�ria: %.2f\nEntre o curso de Letras Vern�culas: %.2f\n\n\nESCORE DA CATEGORIA 'AGRESSIVIDADE AUTORIT�RIA'\n\nEntre o curso de Engenharia Civil: %.2f\nEntre o curso de Medicina: %.2f\nEntre o curso de Hist�ria: %.2f\nEntre o curso de Letras Vern�culas: %.2f\n\n\nESCORE DA CATEGORIA 'CONVENCIONALISMO'\n\nEntre o curso de Engenharia Civil: %.2f\nEntre o curso de Medicina: %.2f\nEntre o curso de Hist�ria: %.2f\nEntre o curso de Letras Vern�culas: %.2f\n\nINDICE DE PROPENS�O AO AUTORITARISMO\n(Quanto mais pr�ximo de 10 mais propenso ao autoritarismo)\nEntre o Curso de Engenharia Civil:%.2f\nEntre o Curso de Medicida:%.2f\nEntre o Curso de Hist�ria:%.2f\nEntre o Curso de Letras Vern�culas:%.2f\n\n",(score1cursoeng/5)/(cursoeng),(score1cursomed/5)/(cursomed),(score1cursohist/5)/(cursohist),(score1cursolet/5)/(cursolet),(score2cursoeng/7)/(cursoeng),(score2cursomed/7)/(cursomed),(score2cursohist/7)/(cursohist),(score2cursolet/7)/(cursolet),(score3cursoeng/5)/(cursoeng),(score3cursomed/5)/(cursomed),(score3cursohist/5)/(cursohist),(score3cursolet/5)/(cursolet),indicecursoeng,indicecursomed,indicecursohist,indicecursolet);
	system("pause");
	system("cls");
	printf("FRENQUENCIA ABSOLUTA POR N�VEL DE CONCORDANCIA ENTRE AS AFIRMA��ES DA ENQUETE\n");
	system("pause");
	system("cls");
	printf("\n\t\tAFIRMA��O 1:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n\t\tAFIRMA��O 2:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d \n\t\tAFIRMA��O 3:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d \n\t\tAFIRMA��O 4:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n",a1discordoT,a1discordo,a1discordoP,a1concordoP,a1concordo,a1concordoT,a2discordoT,a2discordo,a2discordoP,a2concordoP,a2concordo,a2concordoT,a3discordoT,a3discordo,a3discordoP,a3concordoP,a3concordo,a3concordoT,a4discordoT,a4discordo,a4discordoP,a4concordoP,a4concordo,a4concordoT);
	system("pause");
	system("cls");
	printf("\n\t\tAFIRMA��O 5:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n\t\tAFIRMA��O 6:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n\t\tAFIRMA��O 7:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n\t\tAFIRMA��O 8:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n",a5discordoT,a5discordo,a5discordoP,a5concordoP,a5concordo,a5concordoT,a6discordoT,a6discordo,a6discordoP,a6concordoP,a6concordo,a6concordoT,a7discordoT,a7discordo,a7discordoP,a7concordoP,a7concordo,a7concordoT,a8discordoT,a8discordo,a8discordoP,a8concordoP,a8concordo,a8concordoT);
	system("pause");
	system("cls");
	printf("\n\t\tAFIRMA��O 9:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n\t\tAFIRMA��O 10:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n\t\tAFIRMA��O 11:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n\t\tAFIRMA��O 12:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n",a9discordoT,a9discordo,a9discordoP,a9concordoP,a9concordo,a9concordoT,a10discordoT,a10discordo,a10discordoP,a10concordoP,a10concordo,a10concordoT,a11discordoT,a11discordo,a11discordoP,a11concordoP,a11concordo,a11concordoT,a12discordoT,a12discordo,a12discordoP,a12concordoP,a12concordo,a12concordoT);
	system("pause");
	system("cls");
	printf("\n\t\tAFIRMA��O 13:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n\t\tAFIRMA��O 14:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n\t\tAFIRMA��O 15:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n\t\tAFIRMA��O 16:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n",a13discordoT,a13discordo,a13discordoP,a13concordoP,a13concordo,a13concordoT,a14discordoT,a14discordo,a14discordoP,a14concordoP,a14concordo,a14concordoT,a15discordoT,a15discordo,a15discordoP,a15concordoP,a15concordo,a15concordoT,a16discordoT,a16discordo,a16discordoP,a16concordoP,a16concordo,a16concordoT);
	system("pause");
	system("cls");
	printf("\n\t\tAFIRMA��O 17:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n",a17discordoT,a17discordo,a17discordoP,a17concordoP,a17concordo,a17concordoT);
	system("pause");
	system("cls");
	printf("FREQUENCIA RELATIVA POR N�VEL DE CONCORDANCIA ENTRE AS AFIRMA��ES DA ENQUETE\n");
	system("pause");
	system("cls");
	printf("\n\t\tAFIRMA��O 1:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMA��O 2:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMA��O 3:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMA��O 4:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n ",(a1discordoT/a1resultadoconcordancia)*100,(a1discordo/a1resultadoconcordancia)*100,(a1discordoP/a1resultadoconcordancia)*100,(a1concordoP/a1resultadoconcordancia)*100,(a1concordo/a1resultadoconcordancia)*100,(a1concordoT/a1resultadoconcordancia)*100,(a2discordoT/a2resultadoconcordancia)*100,(a2discordo/a2resultadoconcordancia)*100,(a2discordoP/a2resultadoconcordancia)*100,(a2concordoP/a2resultadoconcordancia)*100,(a2concordo/a2resultadoconcordancia)*100,(a2concordoT/a2resultadoconcordancia)*100,(a3discordoT/a3resultadoconcordancia)*100,(a3discordo/a3resultadoconcordancia)*100,(a3discordoP/a3resultadoconcordancia)*100,(a3concordoP/a3resultadoconcordancia)*100,(a3concordo/a3resultadoconcordancia)*100,(a3concordoT/a3resultadoconcordancia)*100,(a4discordoT/a4resultadoconcordancia)*100,(a4discordo/a4resultadoconcordancia)*100,(a4discordoP/a4resultadoconcordancia)*100,(a4concordoP/a4resultadoconcordancia)*100,(a4concordo/a4resultadoconcordancia)*100,(a4concordoT/a4resultadoconcordancia)*100);
	system("pause");
	system("cls");
	printf("\n\t\tAFIRMA��O 5:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMA��O 6:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMA��O 7:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMA��O 8:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%% \n",(a5discordoT/a5resultadoconcordancia)*100,(a5discordo/a5resultadoconcordancia)*100,(a5discordoP/a5resultadoconcordancia)*100,(a5concordoP/a5resultadoconcordancia)*100,(a5concordo/a5resultadoconcordancia)*100,(a5concordoT/a5resultadoconcordancia)*100,(a6discordoT/a6resultadoconcordancia)*100,(a6discordo/a6resultadoconcordancia)*100,(a6discordoP/a6resultadoconcordancia)*100,(a6concordoP/a6resultadoconcordancia)*100,(a6concordo/a6resultadoconcordancia)*100,(a6concordoT/a6resultadoconcordancia)*100,(a7discordoT/a7resultadoconcordancia)*100,(a7discordo/a7resultadoconcordancia)*100,(a7discordoP/a7resultadoconcordancia)*100,(a7concordoP/a7resultadoconcordancia)*100,(a7concordo/a7resultadoconcordancia)*100,(a7concordoT/a7resultadoconcordancia)*100,(a8discordoT/a8resultadoconcordancia)*100,(a8discordo/a8resultadoconcordancia)*100,(a8discordoP/a8resultadoconcordancia)*100,(a8concordoP/a8resultadoconcordancia)*100,(a8concordo/a8resultadoconcordancia)*100,(a8concordoT/a8resultadoconcordancia)*100);
	system("pause");
	system("cls");
	printf("\n\t\tAFIRMA��O 9:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMA��O 10:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMA��O 11:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMA��O 12:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%% \n",(a9discordoT/a9resultadoconcordancia)*100,(a9discordo/a9resultadoconcordancia)*100,(a9discordoP/a9resultadoconcordancia)*100,(a9concordoP/a9resultadoconcordancia)*100,(a9concordo/a9resultadoconcordancia)*100,(a9concordoT/a9resultadoconcordancia)*100,(a10discordoT/a10resultadoconcordancia)*100,(a10discordo/a10resultadoconcordancia)*100,(a10discordoP/a10resultadoconcordancia)*100,(a10concordoP/a10resultadoconcordancia)*100,(a10concordo/a10resultadoconcordancia)*100,(a10concordoT/a10resultadoconcordancia)*100,(a11discordoT/a11resultadoconcordancia)*100,(a11discordo/a11resultadoconcordancia)*100,(a11discordoP/a11resultadoconcordancia)*100,(a11concordoP/a11resultadoconcordancia)*100,(a11concordo/a11resultadoconcordancia)*100,(a11concordoT/a11resultadoconcordancia)*100,(a12discordoT/a12resultadoconcordancia)*100,(a12discordo/a12resultadoconcordancia)*100,(a12discordoP/a12resultadoconcordancia)*100,(a12concordoP/a12resultadoconcordancia)*100,(a12concordo/a12resultadoconcordancia)*100,(a12concordoT/a12resultadoconcordancia)*100);		
	system("pause");
	system("cls");
	printf("\n\t\tAFIRMA��O 13:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMA��O 14:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMA��O 15:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMA��O 16:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%% \n",(a13discordoT/a13resultadoconcordancia)*100,(a13discordo/a13resultadoconcordancia)*100,(a13discordoP/a13resultadoconcordancia)*100,(a13concordoP/a13resultadoconcordancia)*100,(a13concordo/a13resultadoconcordancia)*100,(a13concordoT/a13resultadoconcordancia)*100,(a14discordoT/a14resultadoconcordancia)*100,(a14discordo/a14resultadoconcordancia)*100,(a14discordoP/a14resultadoconcordancia)*100,(a14concordoP/a14resultadoconcordancia)*100,(a14concordo/a14resultadoconcordancia)*100,(a14concordoT/a14resultadoconcordancia)*100,(a15discordoT/a15resultadoconcordancia)*100,(a15discordo/a15resultadoconcordancia)*100,(a15discordoP/a15resultadoconcordancia)*100,(a15concordoP/a15resultadoconcordancia)*100,(a15concordo/a15resultadoconcordancia)*100,(a15concordoT/a15resultadoconcordancia)*100,(a16discordoT/a16resultadoconcordancia)*100,(a16discordo/a16resultadoconcordancia)*100,(a16discordoP/a16resultadoconcordancia)*100,(a16concordoP/a16resultadoconcordancia)*100,(a16concordo/a16resultadoconcordancia)*100,(a16concordoT/a16resultadoconcordancia)*100);		
	system("pause");
	system("cls");
	printf("\n\t\tAFIRMA��O 17:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n",(a17discordoT/a17resultadoconcordancia)*100,(a17discordo/a17resultadoconcordancia)*100,(a17discordoP/a17resultadoconcordancia)*100,(a17concordoP/a17resultadoconcordancia)*100,(a17concordo/a17resultadoconcordancia)*100,(a17concordoT/a17resultadoconcordancia)*100);
	system ("pause");
return 0;
}
