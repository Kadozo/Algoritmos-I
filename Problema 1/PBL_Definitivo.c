/*******************************************************************************
Autor: Thiago Cardozo de Jesus
Componente Curricular: Algoritmos I
Concluido em: 22/09/2018
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.
******************************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#define PESO 3

int escolhaidade,escolhacurso,escolha=0,repetir=0,pesquisa=0,escolhasexo=0; //As váriaveis desta linha, são basicamente feitas para o receber a informação passada pelo usuário e enviá-las para outras variáveis,geralmente associadas a bloco de condição//
int sexoM=0,sexoF=0,idade18=0,idade21=0,idade24=0,cursoeng=0,cursomed=0,cursohist=0,cursolet=0,totalP;//As váriaveis desta linha, são, respectivamente, contadores para:O sexo do participante, as 3 faixas etárias, as 4 opções de curso e o total de participantes
 /*O Bloco de variáveis a seguir, é relacionada ao calculo de frequencia relativa e absoluta dos níveis de concordância de cada questão
 Tais variáveis estão indentificadas em (a[n][niveldeconcordancia]) onde: an é a número da afirmação,ex: a1= afirmação 1, a2= afirmação2.
 E o nívei de concordancia está identificado como:discordoT para discordo totalmente,discordo para discordo,discordoP para discordo Parcialmente,concordoP para
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
/*O Bloco a seguir consiste em váriaveis responsáveis em guardar as soma dos níveis de concordancia para cada questão da enquete, serão ultilizadas no cálculo
da frequencia relativa.Elas estão identificadas em a[n]resultadoconcordancia, onde n é o número da afirmação a qual a variável é referente */
float a1resultadoconcordancia,a2resultadoconcordancia,a3resultadoconcordancia,a4resultadoconcordancia,a5resultadoconcordancia,a6resultadoconcordancia,a7resultadoconcordancia;
float a8resultadoconcordancia,a9resultadoconcordancia,a10resultadoconcordancia,a11resultadoconcordancia,a12resultadoconcordancia,a13resultadoconcordancia,a14resultadoconcordancia;
float a15resultadoconcordancia,a16resultadoconcordancia,a17resultadoconcordancia;
/*A variável com a palavra "score1" é referente ao escore da primeira categoria,Submissão à autoridade.há algumas váriações da mesma,quanto a sua especificidade: 
ex:score1cursoeng (escore da 1ª categoria para o curso de engenharia),score1sexoM (escore da 1º categoria para o sexo masculino)
A mesma lógica se aplica as variáveis score2,referente à categoria Agressividade autoritária, e score3,referente à categoria Convencionalismo.*/
float score1=0,score2=0,score3=0,indicegeral=0,score1sexoM=0,score1idade18=0,score1cursoeng=0,score2sexoM=0,score2idade18=0,score2cursoeng=0,score3sexoM=0,score3idade18=0,score3cursoeng=0;
float score1cursomed=0,score2cursomed=0,score3cursomed=0,score1cursohist=0,score2cursohist=0,score3cursohist=0,score1cursolet=0,score2cursolet=0,score3cursolet=0,score1idade21=0;
float score2idade21=0,score3idade21=0,score1idade24=0,score2idade24=0,score3idade24=0,score1sexoF=0,score2sexoF=0,score3sexoF=0,totalscore1=0,totalscore2=0,totalscore3=0;
/*A próxima linha de código é referente,respectivamente, às váriaveis relacionadas a: soma dos contadores de nível de concordancia, a acumulação dos 3 escores das categorias
e aos indices de propensão para cada opção de sexo, */
float resultadoconcordancia=0,score1total=0,score2total=0,score3total=0,indicetotalP=0,indicesexoM=0,indicesexoF=0,indiceidade18=0,indiceidade21=0,indiceidade24=0,indicecursoeng=0,indicecursomed=0,indicecursohist=0,indicecursolet=0;
int main(){
	system("color C");
	do{
		score1=0;
		score2=0;
		score3=0;
		setlocale(LC_ALL, "Portuguese");
		printf("A seguir serão mostrada algumas afirmações.\nResponda-a ,com o número correspondente às formas de respostas predefinidas, aquela que mais se adequa à sua opinião\n\nTecle:\n[1]Para responder: Discordo totalmente\n[2]Para responder: Discordo \n[3]Para responder: Discordo parcialmente\n[4]Para responder: Concordo parcialmente\n[5]Para responder: Concordo\n[6]Para responder: Concordo Totalmente");
		do{
			printf("\n\nAfirmação 1:O que este país necessita, principalmente,antes das leis ou planos políticos, é de alguns lideres valentes, incansáveis e dedicados em quem o povo possa depositar a sua fé\nResposta:  ");
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
		        	printf("\nResposta inválida.Tente uma tecla válida\n\n\n");
		        	break;
		    	}	
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirmação 2:A obediência e o respeito à autoridade são as principais virtudes que devemos ensinar as nossas crianças\nResposta: ");
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
					printf("\nResposta inválida.Tente uma tecla válida\n\n\n");							
				}		
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirmação 3:Não há nada pior do que uma pessoa que não sente profundo amor, gratidão e respeito por seus pais\nResposta: ");
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
					printf("\nResposta inválida.Tente uma tecla válida\n\n\n");								
				}			
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirmação 4:Nenhuma pessoa decente,normal e em seu são juízo pensaria em ofender um amigo ou parente próximo\nResposta: ");
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
					printf("\nResposta inválida.Tente uma tecla válida\n\n\n");								
				}		
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirmação 5:O policial é um guerreiro de Deus para impor a ordem e proteger as pessoas de bem\nResposta: ");
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
					printf("\nResposta inválida.Tente uma tecla válida\n\n\n");				
				}	
		}while (escolha<=0 || escolha>=7);
		escolha=0;
		do{
			printf("\n\nAfirmação 6:A maioria de nossos problemas sociais estaria resolvida se pudéssemos nos livrar das pessoas imorais,dos marginais e dos pervertidos\nResposta: ");
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
					printf("\nResposta inválida.Tente uma tecla válida\n\n\n");				
				}						
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirmação 7:Se falássemos menos e trabalhássemos mais,todos estaríamos melhor\nResposta: ");
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
					printf("\nResposta inválida.Tente uma tecla válida\n\n\n");	
				}	
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirmação 8:Deve-se castigar sempre todo insulto à nossa honra \nResposta: ");
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
					printf("\nResposta inválida.Tente uma tecla válida\n\n\n");				
				}										
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirmação 9:Os crimes sexuais, tais como estupro ou ataques a crianças merecem mais que prisão;quem comete esses crimes deveria receber punição física publicamente ou receber castigo pior\nResposta: ");
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
					printf("\nResposta inválida.Tente uma tecla válida\n\n\n");				
				}						
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirmação 10:Os homossexuais são quase criminosos e deveriam receber um castigo severo\nResposta: ");
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
					printf("\nResposta inválida.Tente uma tecla válida\n\n\n");				
				}										
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirmação 11:Às vezes, os jovens têm ideias rebeldes que,com os anos, deverão superar para acalmar os seus pensamentos\nResposta: ");
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
					printf("\nResposta inválida.Tente uma tecla válida\n\n\n");				
				}										
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirmação 12:Hoje em dia, as pessoas se intrometem cada vez mais em assuntos que deveriam ser somente pessoais e privados\nResposta: ");
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
					printf("\nResposta inválida.Tente uma tecla válida\n\n\n");				
				}						
		}while (escolha<=0 || escolha>=7);
		escolha=0;
		do{
			printf("\n\nAfirmação 13:A ciência tem o seu lugar, mas há muitas coisas importantes que a mente humana jamais poderá compreender\nResposta: ");
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
					printf("\nResposta inválida.Tente uma tecla válida\n\n\n");				
				}										
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirmação 14:Os homens podem ser divididos em duas classes definidas:Fortes e Fracos\nResposta: ");
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
					printf("\nResposta inválida.Tente uma tecla válida\n\n\n");				
				}									
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirmação 15:Um indivíduo de más maneiras,maus costumes e má educação dificilmente pode fazer amizade com pessoas decentes\nResposta: ");
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
					printf("\nResposta inválida.Tente uma tecla válida\n\n\n");				
				}									
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirmação 16:Todos devemos ter fé absoluta em um poder sobrenatural,cujas decisões devemos acatar\nResposta: ");
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
					printf("\nResposta inválida.Tente uma tecla válida\n\n\n");				
				}									
		}while (escolha<=0 || escolha>=7);
		do{
			printf("\n\nAfirmação 17:Pobreza é consequencia de falta de vontade de querer trabalhar\nResposta: ");
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
					printf("\nResposta inválida.Tente uma tecla válida\n\n\n");				
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
		printf ("Digite o número dentre as opções que corresponde ao seu sexo:\n\n[1]Homem\n[2]Mulher\nResposta: ");
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
			printf("escolha inválida\n\n");
	}while(escolhasexo<=0||escolhasexo>=3);
	do {
		printf("Digite o número dentre opções que corresponde à sua idade:\n\n[1] 18 anos a 20 anos\n[2] 21 anos a 23 anos\n[3] Acima de 23 anos\nResposta: ");
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
			printf("Escolha inválida\n\n");
	}while (escolhaidade>=4 || escolhaidade<=0);
	do {
		printf("Digite o número dentre as opções que corresponde à seu curso\n\n[1] Engenharia Civil\n[2] Medicina\n[3] História\n[4] Letras Vernáculas\nResposta: ");
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
		printf("Escolha inválida\n\n");
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
	printf("Se deseja repetir o questionário digite [1]: ");
	scanf("%d",&repetir);
	system("cls");
	}while(repetir==1);
	printf("Total de entrevistados: %d",totalP);
	printf("\n\n\nTotal de entrevistados por sexo:\n\nFeminino: %d\nMasculino: %d",sexoF,sexoM);
	printf("\n\n\nTotal de entrevistados por faixa etária:\n\n18 a 20 anos: %d\n21 a 23 anos: %d\n24 anos ou acima: %d",idade18,idade21,idade24);
	printf("\n\n\nTotal de entrevistados por curso\n\nEngenharia Civil: %d\nMedicina: %d\nHistória: %d\nLetras Vernáculas: %d\n\n\n",cursoeng,cursomed,cursohist,cursolet);
	system("pause");
	system("cls");
	printf("\n\n\nESCORE E INDICE GERAL DE TODOS OS PARTICIPANTES\n\n\n");
	system("pause");
	system("cls"); //TRATAMENTO DE ERROS
	printf("\nESCORE DA CATEGORIA 'SUBMISSÃO À AUTORIDADE'\n\n%.2f\n\n\n ESCORE DA CATEGORIA 'AGRESSIVIDADE AUTORITÁRIA'\n\n%.2f\n\n\nESCORE DA CATEGORIA 'CONVENCIONALISMO'\n\n%.2f\n\n\nINDICE DE PROPENSÃO AO AUTORITARISMO\n(Quanto mais próximo de 10 mais propenso ao autoritarismo)\n%.2f\n\n",(score1total/5)/(totalP),(score2total/7)/(totalP),(score3total/5)/(totalP),indicetotalP);
	system("pause");
	system("cls");
	printf("\n\n\nESCORE E INDICE GERAL POR FAIXA ETÁRIA\n\n\n");
	system("pause");
	system("cls");
	printf("\nESCORE DA CATEGORIA 'SUBMISSÃO À AUTORIDADE'\n\nEntre 18 a 20 anos: %.2f\nEntre 21 a 23 anos: %.2f\nAcima de 24 anos: %.2f\n\n\nESCORE DA CATEGORIA 'AGRESSIVIDADE AUTORITÁRIA'\n\nEntre 18 a 20 anos: %.2f\nEntre 21 a 23 anos: %.2f\nAcima de 24 anos: %.2f\n\n\nESCORE DA CATEGORIA 'CONVENCIONALISMO'\n\nEntre 18 a 20 anos: %.2f\nEntre 21 a 23 anos: %.2f\nAcima de 24 anos: %f\n\nINDICE DE PROPENSÃO AO AUTORITARISMO\n(Quanto mais próximo de 10 mais propenso ao autoritarismo)\n\nEntre 18 a 20 anos: %.2f\nEntre21 a 23 anos: %.2f\nAcima de 24 anos: %.2f\n",(score1idade18/5)/(idade18),(score1idade21/5)/(idade21),(score1idade24/5)/(idade24),(score2idade18/7)/(idade18),(score2idade21/7)/(idade21),(score2idade24/7)/(idade24),(score3idade18/5)/(idade18),(score3idade21/5)/(idade21),(score3idade24/5)/(idade24),indiceidade18,indiceidade21,indiceidade24);
	system("pause");
	system("cls");
	printf("\n\n\nESCORE E INDICE GERAL POR SEXO\n\n\n");
	system("pause");
	system("cls");
	printf("\nESCORE DA CATEGORIA 'SUBMISSÃO À AUTORIDADE'\n\nEntre o Sexo Masculino: %.2f\nEntre o Sexo Feminino: %.2f\n\n\nESCORE DA CATEGORIA 'AGRESSIVIDADE AUTORITÁRIA'\n\nEntre o Sexo Masculino: %.2f\n\Entre o Sexo Feminino: %.2f\n\n\nESCORE DA CATEGORIA 'CONVENCIONALISMO'\n\nEntre o Sexo Masculino: %.2f\nEntre o Sexo Feminino: %.2f\n\n\nINDICE DE PROPENSÃO AO AUTORITARISMO\n(Quanto mais próximo de 10 mais propenso ao autoritarismo)\n\nEntre o sexo Masculino: %.2f\nEntre o sexo Feminino: %.2f\n\n",(score1sexoM/5)/(sexoM),(score1sexoF/5)/(sexoF),(score2sexoM/7)/(sexoM),(score2sexoF/7)/(sexoF),(score3sexoM/5)/(sexoM),(score3sexoF/5)/(sexoF),indicesexoM,indicesexoF);
	system("pause");
	system("cls");
	printf("\n\n\nESCORE E INDICE GERAL POR CURSO\n\n\n");
	system("pause");
	system("cls");
	printf("\nESCORE DA CATEGORIA 'SUBMISSÃO À AUTORIDADE'\n\nEntre o curso de Engenharia Civil: %.2f\nEntre o curso de Medicina: %.2f\nEntre o curso de História: %.2f\nEntre o curso de Letras Vernáculas: %.2f\n\n\nESCORE DA CATEGORIA 'AGRESSIVIDADE AUTORITÁRIA'\n\nEntre o curso de Engenharia Civil: %.2f\nEntre o curso de Medicina: %.2f\nEntre o curso de História: %.2f\nEntre o curso de Letras Vernáculas: %.2f\n\n\nESCORE DA CATEGORIA 'CONVENCIONALISMO'\n\nEntre o curso de Engenharia Civil: %.2f\nEntre o curso de Medicina: %.2f\nEntre o curso de História: %.2f\nEntre o curso de Letras Vernáculas: %.2f\n\nINDICE DE PROPENSÃO AO AUTORITARISMO\n(Quanto mais próximo de 10 mais propenso ao autoritarismo)\nEntre o Curso de Engenharia Civil:%.2f\nEntre o Curso de Medicida:%.2f\nEntre o Curso de História:%.2f\nEntre o Curso de Letras Vernáculas:%.2f\n\n",(score1cursoeng/5)/(cursoeng),(score1cursomed/5)/(cursomed),(score1cursohist/5)/(cursohist),(score1cursolet/5)/(cursolet),(score2cursoeng/7)/(cursoeng),(score2cursomed/7)/(cursomed),(score2cursohist/7)/(cursohist),(score2cursolet/7)/(cursolet),(score3cursoeng/5)/(cursoeng),(score3cursomed/5)/(cursomed),(score3cursohist/5)/(cursohist),(score3cursolet/5)/(cursolet),indicecursoeng,indicecursomed,indicecursohist,indicecursolet);
	system("pause");
	system("cls");
	printf("FRENQUENCIA ABSOLUTA POR NÍVEL DE CONCORDANCIA ENTRE AS AFIRMAÇÕES DA ENQUETE\n");
	system("pause");
	system("cls");
	printf("\n\t\tAFIRMAÇÃO 1:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n\t\tAFIRMAÇÃO 2:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d \n\t\tAFIRMAÇÃO 3:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d \n\t\tAFIRMAÇÃO 4:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n",a1discordoT,a1discordo,a1discordoP,a1concordoP,a1concordo,a1concordoT,a2discordoT,a2discordo,a2discordoP,a2concordoP,a2concordo,a2concordoT,a3discordoT,a3discordo,a3discordoP,a3concordoP,a3concordo,a3concordoT,a4discordoT,a4discordo,a4discordoP,a4concordoP,a4concordo,a4concordoT);
	system("pause");
	system("cls");
	printf("\n\t\tAFIRMAÇÃO 5:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n\t\tAFIRMAÇÃO 6:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n\t\tAFIRMAÇÃO 7:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n\t\tAFIRMAÇÃO 8:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n",a5discordoT,a5discordo,a5discordoP,a5concordoP,a5concordo,a5concordoT,a6discordoT,a6discordo,a6discordoP,a6concordoP,a6concordo,a6concordoT,a7discordoT,a7discordo,a7discordoP,a7concordoP,a7concordo,a7concordoT,a8discordoT,a8discordo,a8discordoP,a8concordoP,a8concordo,a8concordoT);
	system("pause");
	system("cls");
	printf("\n\t\tAFIRMAÇÃO 9:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n\t\tAFIRMAÇÃO 10:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n\t\tAFIRMAÇÃO 11:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n\t\tAFIRMAÇÃO 12:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n",a9discordoT,a9discordo,a9discordoP,a9concordoP,a9concordo,a9concordoT,a10discordoT,a10discordo,a10discordoP,a10concordoP,a10concordo,a10concordoT,a11discordoT,a11discordo,a11discordoP,a11concordoP,a11concordo,a11concordoT,a12discordoT,a12discordo,a12discordoP,a12concordoP,a12concordo,a12concordoT);
	system("pause");
	system("cls");
	printf("\n\t\tAFIRMAÇÃO 13:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n\t\tAFIRMAÇÃO 14:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n\t\tAFIRMAÇÃO 15:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n\t\tAFIRMAÇÃO 16:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n",a13discordoT,a13discordo,a13discordoP,a13concordoP,a13concordo,a13concordoT,a14discordoT,a14discordo,a14discordoP,a14concordoP,a14concordo,a14concordoT,a15discordoT,a15discordo,a15discordoP,a15concordoP,a15concordo,a15concordoT,a16discordoT,a16discordo,a16discordoP,a16concordoP,a16concordo,a16concordoT);
	system("pause");
	system("cls");
	printf("\n\t\tAFIRMAÇÃO 17:\nDiscordo Totalmente: %d\nDiscordo: %d\nDiscordo Parcialmente: %d\nConcordo Parcialmente; %d\nConcordo: %d\nConcordo Totalmente: %d\n",a17discordoT,a17discordo,a17discordoP,a17concordoP,a17concordo,a17concordoT);
	system("pause");
	system("cls");
	printf("FREQUENCIA RELATIVA POR NÍVEL DE CONCORDANCIA ENTRE AS AFIRMAÇÕES DA ENQUETE\n");
	system("pause");
	system("cls");
	printf("\n\t\tAFIRMAÇÃO 1:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMAÇÃO 2:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMAÇÃO 3:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMAÇÃO 4:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n ",(a1discordoT/a1resultadoconcordancia)*100,(a1discordo/a1resultadoconcordancia)*100,(a1discordoP/a1resultadoconcordancia)*100,(a1concordoP/a1resultadoconcordancia)*100,(a1concordo/a1resultadoconcordancia)*100,(a1concordoT/a1resultadoconcordancia)*100,(a2discordoT/a2resultadoconcordancia)*100,(a2discordo/a2resultadoconcordancia)*100,(a2discordoP/a2resultadoconcordancia)*100,(a2concordoP/a2resultadoconcordancia)*100,(a2concordo/a2resultadoconcordancia)*100,(a2concordoT/a2resultadoconcordancia)*100,(a3discordoT/a3resultadoconcordancia)*100,(a3discordo/a3resultadoconcordancia)*100,(a3discordoP/a3resultadoconcordancia)*100,(a3concordoP/a3resultadoconcordancia)*100,(a3concordo/a3resultadoconcordancia)*100,(a3concordoT/a3resultadoconcordancia)*100,(a4discordoT/a4resultadoconcordancia)*100,(a4discordo/a4resultadoconcordancia)*100,(a4discordoP/a4resultadoconcordancia)*100,(a4concordoP/a4resultadoconcordancia)*100,(a4concordo/a4resultadoconcordancia)*100,(a4concordoT/a4resultadoconcordancia)*100);
	system("pause");
	system("cls");
	printf("\n\t\tAFIRMAÇÃO 5:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMAÇÃO 6:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMAÇÃO 7:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMAÇÃO 8:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%% \n",(a5discordoT/a5resultadoconcordancia)*100,(a5discordo/a5resultadoconcordancia)*100,(a5discordoP/a5resultadoconcordancia)*100,(a5concordoP/a5resultadoconcordancia)*100,(a5concordo/a5resultadoconcordancia)*100,(a5concordoT/a5resultadoconcordancia)*100,(a6discordoT/a6resultadoconcordancia)*100,(a6discordo/a6resultadoconcordancia)*100,(a6discordoP/a6resultadoconcordancia)*100,(a6concordoP/a6resultadoconcordancia)*100,(a6concordo/a6resultadoconcordancia)*100,(a6concordoT/a6resultadoconcordancia)*100,(a7discordoT/a7resultadoconcordancia)*100,(a7discordo/a7resultadoconcordancia)*100,(a7discordoP/a7resultadoconcordancia)*100,(a7concordoP/a7resultadoconcordancia)*100,(a7concordo/a7resultadoconcordancia)*100,(a7concordoT/a7resultadoconcordancia)*100,(a8discordoT/a8resultadoconcordancia)*100,(a8discordo/a8resultadoconcordancia)*100,(a8discordoP/a8resultadoconcordancia)*100,(a8concordoP/a8resultadoconcordancia)*100,(a8concordo/a8resultadoconcordancia)*100,(a8concordoT/a8resultadoconcordancia)*100);
	system("pause");
	system("cls");
	printf("\n\t\tAFIRMAÇÃO 9:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMAÇÃO 10:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMAÇÃO 11:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMAÇÃO 12:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%% \n",(a9discordoT/a9resultadoconcordancia)*100,(a9discordo/a9resultadoconcordancia)*100,(a9discordoP/a9resultadoconcordancia)*100,(a9concordoP/a9resultadoconcordancia)*100,(a9concordo/a9resultadoconcordancia)*100,(a9concordoT/a9resultadoconcordancia)*100,(a10discordoT/a10resultadoconcordancia)*100,(a10discordo/a10resultadoconcordancia)*100,(a10discordoP/a10resultadoconcordancia)*100,(a10concordoP/a10resultadoconcordancia)*100,(a10concordo/a10resultadoconcordancia)*100,(a10concordoT/a10resultadoconcordancia)*100,(a11discordoT/a11resultadoconcordancia)*100,(a11discordo/a11resultadoconcordancia)*100,(a11discordoP/a11resultadoconcordancia)*100,(a11concordoP/a11resultadoconcordancia)*100,(a11concordo/a11resultadoconcordancia)*100,(a11concordoT/a11resultadoconcordancia)*100,(a12discordoT/a12resultadoconcordancia)*100,(a12discordo/a12resultadoconcordancia)*100,(a12discordoP/a12resultadoconcordancia)*100,(a12concordoP/a12resultadoconcordancia)*100,(a12concordo/a12resultadoconcordancia)*100,(a12concordoT/a12resultadoconcordancia)*100);		
	system("pause");
	system("cls");
	printf("\n\t\tAFIRMAÇÃO 13:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMAÇÃO 14:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMAÇÃO 15:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n\t\tAFIRMAÇÃO 16:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%% \n",(a13discordoT/a13resultadoconcordancia)*100,(a13discordo/a13resultadoconcordancia)*100,(a13discordoP/a13resultadoconcordancia)*100,(a13concordoP/a13resultadoconcordancia)*100,(a13concordo/a13resultadoconcordancia)*100,(a13concordoT/a13resultadoconcordancia)*100,(a14discordoT/a14resultadoconcordancia)*100,(a14discordo/a14resultadoconcordancia)*100,(a14discordoP/a14resultadoconcordancia)*100,(a14concordoP/a14resultadoconcordancia)*100,(a14concordo/a14resultadoconcordancia)*100,(a14concordoT/a14resultadoconcordancia)*100,(a15discordoT/a15resultadoconcordancia)*100,(a15discordo/a15resultadoconcordancia)*100,(a15discordoP/a15resultadoconcordancia)*100,(a15concordoP/a15resultadoconcordancia)*100,(a15concordo/a15resultadoconcordancia)*100,(a15concordoT/a15resultadoconcordancia)*100,(a16discordoT/a16resultadoconcordancia)*100,(a16discordo/a16resultadoconcordancia)*100,(a16discordoP/a16resultadoconcordancia)*100,(a16concordoP/a16resultadoconcordancia)*100,(a16concordo/a16resultadoconcordancia)*100,(a16concordoT/a16resultadoconcordancia)*100);		
	system("pause");
	system("cls");
	printf("\n\t\tAFIRMAÇÃO 17:\nDiscordo Totalmente: %.2f%%\nDiscordo: %.2f%%\nDiscordo Parcialmente: %.2f%%\nConcordo Parcialmente; %.2f%%\nConcordo: %.2f%%\nConcordo Totalmente: %.2f%%\n",(a17discordoT/a17resultadoconcordancia)*100,(a17discordo/a17resultadoconcordancia)*100,(a17discordoP/a17resultadoconcordancia)*100,(a17concordoP/a17resultadoconcordancia)*100,(a17concordo/a17resultadoconcordancia)*100,(a17concordoT/a17resultadoconcordancia)*100);
	system ("pause");
return 0;
}
