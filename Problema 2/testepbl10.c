/*******************************************************************************
Autor: Thiago Cardozo de Jesus
Componente Curricular: Algoritmos I
Concluido em: 21/11/2018
Declaro que este c�digo foi elaborado por mim de forma individual e n�o cont�m nenhum
trecho de c�digo de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e p�ginas ou documentos eletr�nicos da Internet. Qualquer trecho de c�digo
de outra autoria que n�o a minha est� destacado com uma cita��o para o autor e a fonte
do c�digo, e estou ciente que estes trechos n�o ser�o considerados para fins de avalia��o.
******************************************************************************************/
#include<stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
void novaentrevista();
void cod(char [100][10][40]);
void frequenciaabs();
void filtrocurso();
float mediatotal();
void filtrosexo();
void filtroidade();
int main()
{
	int menu; //armazena a escolha do usuario para acessar o menu
	int escolhafiltro; // armazena a escolha do usuario em rela�ao a qual filtro utilizar
	setlocale(LC_ALL, "Portuguese");
	system("color C");
	printf("*******N�cleo de Estudos da Democracia-Enquetes Flex�veis*******");
	do{
		menu=0;
		printf("\n\nDigite:\n\n[1]Para da entrada de novas entrevistas\n[2]Frequ�ncia Absoluta de cada n�vel de concord�ncia de cada quest�o e sua moda\n");
		printf("[3]Para computar a m�dia de todos os participantes at� o momento\n[4]Para o filtro de resultados\n[5]Para sair do programa\n");
		fflush(stdin);
		scanf("%d",&menu);
		fflush(stdin);
		switch(menu){
			case 1:
				system("cls");
				novaentrevista();
				system("cls");
				main();
				break;
			case 2:
				frequenciaabs();
				system("cls");
				main();
				break;
			case 3:
				system("cls");
				printf("A m�dia at� o momento � [%.2f]\n",mediatotal());
				system("pause");
				system("cls");
				main();
				break;
			case 4:
				//break;
				printf("Que tipo de filtro voc� deseja ultilizar?\n[1]Para o filtro por curso\n[2]Para o filtro por sexo\n[3]Para o filtro por faixa de idade\n");
				fflush(stdin);
				scanf("%d",&escolhafiltro);
				fflush(stdin);
				switch (escolhafiltro){
					case 1:
						fflush(stdin);
						filtrocurso();
						fflush(stdin);
						system("cls");
						main();
						break;
					case 2:
						fflush(stdin);
						filtrosexo();
						fflush(stdin);
						system("cls");
						main();
						break;
					case 3:
						fflush(stdin);
						filtroidade();
						fflush(stdin);
						system("cls");
						main();
						break;
					default:
						printf("Resposta inv�lida");
						main();
						break;	
				}
				break;
			case 5:
				return 0;			
			default:
				printf("Escolha inv�lida\n");
				printf("Digite qualquer tecla para continuar\n");
				getchar();
				system("cls");
				main();
				break;
		}
	}while(menu<=0||menu>5);
return 0;
}


void novaentrevista(){
	char codigo[100][10][40];
	cod(codigo); //procedimento para implementar numa matriz 3d,nesse caso c�digo, os c�digos de likert do .txt
	int x=0;/*vari�vel respons�vel pelo controle do loop de grava��o dos dados do .txt de perguntas para a matriz, t�mbem ultilizada para saber a quantidade de perguntas que h� no question�rio*/
	int i,y=0,z=0;
	int a; // vari�vel utilizada para controlar o la�o de repeti��o de exibi��o das escalas de likert ao usu�rio
	int soma=0;// acumulador para fazer o escore individual
	int limite=0; // v�riavel que pega a quantidade de n�veis de likert e serve como codi��o de parada para o loop que mostra tais n�veis de escala ao usuario 
	int codigopergunta=0,codigolikert=0; //variaveis para fazer a verifica��o dos c�digos dos dois arquivos .txt "perguntas" e "tiposderespostas"
	char perguntas[100][250]={'\0'};
	char str[100]="respostas.txt";
	FILE *pquestoes;
	pquestoes=fopen("questoes.txt","r");
	if (pquestoes==NULL){
		printf("Arquivo de perguntas n�o pode ser aberto");
		getchar();
		system("exit");
	}
	FILE *prespostas;
	char resposta[4][210]={'\0'};
	prespostas=fopen("respostas.txt","a+");
	if (prespostas==NULL){
		printf("Arquivo de respostas n�o pode ser aberto");
		getchar();
		system("exit");
	}
	printf("Por favor, digite o nome do seu curso\nOBS:*Primeira letra mai�scula, sem acentua��o ou caracteres especiais*\n");
	gets(resposta[0]);
	fprintf(prespostas,"%s\n",resposta[0]);
	printf("Por favor, digite o seu sexo\nOBS: *Tudo em letras min�sculas*\n");
	gets(resposta[1]);
	fprintf(prespostas,"%s\n",resposta[1]);
	printf("Por favor, digite o sua idade\n");
	gets(resposta[2]);
	fprintf(prespostas,"%s\n",resposta[2]);
	printf("A seguir ser� mostrado algumas afirma��es, responda-as segundo as escalas determinadas\n");
	system("pause");
	system("cls");
	// *LEMBRETE quando for ler as sequencias de respostas ler em formato inteiro e n�o char 
	while(fgets(perguntas[x],250,pquestoes)!=NULL){ //copia os dados do arquivo apontado pelo ponteiro 'questoes' para a matriz perguntas
	x++;//contador de linhas do arquivo
	}
	for(i=0;i<x;i++){ 
		if (i%2==0){//printa apenas as linhas de perguntas
			puts(perguntas[i]);
			codigopergunta=atoi(perguntas[i+1]);
			codigolikert=atoi(codigo[y][z]);
			while(codigopergunta!=codigolikert){ // la�o para encontrar o c�digo que corresponde as perguntas
				y=y+3;// para ir pulando para a linha especifica da matriz que corresponde ao n�mero do c�digo
				codigolikert=atoi(codigo[y][z]); // salva o novo valor da v�riavel codigolikert para continuar a verifica��o
			}
			limite=atoi(codigo[y+1][z]);
			for(a=0;a<limite;a++){ // la�o de repeti��o para printar as escalas dispon�veis para determinada quest�o para o usu�rio
				printf("Digite [%d] Para responder %s\n",a+1,codigo[y+2][z]);
				z++;
			} 
			printf("\n");
			gets(resposta[3]);
			fprintf(prespostas,"%s ",resposta[3]);
			soma=soma+atoi(resposta[3]); //acumula��o para fazer o escore individual
			y=0;
			codigopergunta=0;
			codigolikert=0;
			z=0;
			system("cls");
		}
	}
	fprintf(prespostas,"\n");
	fclose(pquestoes);
	fclose(prespostas);
	printf("Seu Escore individual foi: %.2f\n",(float)soma/(x/2));
	printf("Pressione qualquer tecla para voltar ao menu principal: ");
	getchar();
	system("cls");
}


void cod(char codigo[100][10][40]){ //procedimento para implementar os c�digos do .txt numa matriz 3d 
	FILE *tiposrespostas;
	tiposrespostas=fopen("tiposrespostas.txt","r");
	char string[250]; //Vetor usado para salvar a string de nivel de concordancia
	int max,linha=0,coluna=0,profundidade=0; // v�riaveis usadas para navegar nos indices da matriz tridimensional
	int i=0;//V�riavel para navegar no vetor de n�vel de concordancia para verificar a presen�a de v�rgulas
	/*codigo[100][10][40]*/
	while(feof(tiposrespostas)==0){
		fgets(string,250,tiposrespostas);
		while (string[i]!= '\n'){
			if(string[i]!=','){
				codigo[linha][coluna][profundidade]=string[i];
				profundidade++;
			}
			else{
				codigo[linha][coluna][profundidade]='\0';
				profundidade=0;
				coluna++;
			}
			i++;		
		}
		i=0;
		profundidade=0;
		coluna=0;
		linha++;
	}
	max=linha;
fclose(tiposrespostas);
}


void frequenciaabs(){
	printf("A seguir ser� feita a contagem da frequencia");
	getchar();
	FILE* prespostas;
	prespostas=fopen("respostas.txt","r");
	FILE* pquestoes;
	pquestoes=fopen("questoes.txt","r");
	if (prespostas==NULL){
		printf("Arquivo n�o pode ser aberto");
		getchar();
		system("exit");
	}
	if (pquestoes==NULL){
		printf("Arquivo n�o pode ser aberto");
		getchar();
		system("exit");
	}
	int numcont=1; // V�riavel para saber qual a ultima contagem de frequencia do programa
	char respostas[4000][200]; //matriz para armazenar o bloco de respostas
	int x=0,i=0,j=0,z=0,a,nivel,limite,k=1,m=1;
	int flinha=0,fcoluna=0; // variaveis para navegar na matriz das frequencias
	int auxlinha=0,auxcoluna=0; // variaveis para navegar na matriz 3d do bloco de codigo de likert
	int frequencia[100][10]={0}; //matriz para salvar as frequencias dos niveis de concordancia
	char perguntas[200][200]; //matriz para armazenar o bloco de perguntas
	char c[100][10][40];//matriz para armazenar o nivel de likert
	char s[1];
	int codigopergunta,codigolikert;
	cod(c);
	while(fgets(respostas[x],200,prespostas)!=NULL){
		x++; // serve como contador para o numero de respostas
	}
	while(fgets(perguntas[z],200,pquestoes)!=NULL){
		z++;// serve como contador para o n�mero de perguntas
	}
	for(i=3;i<=x;i+=4){// para acessar apenas as linhas da matriz que correspondem as sequencia de respostas
		system("cls");
		printf("Respostas de [%d] entrevistados:\n",k);
		for(j=0;j<z;j+=2){//esse for ta trabalhando em cada linha de resposta por entrevistado
			printf("*FREQU�NCIA AT� A AFIRMA��O %d*\n",m);
			nivel=respostas[i][j]-'0';
			codigopergunta=perguntas[j+1][0]-'0';
			codigolikert=c[auxlinha][auxcoluna][0]-'0';
			
			while(codigopergunta!=codigolikert){ // la�o para encontrar o c�digo que corresponde as perguntas
				auxlinha=auxlinha+3;// para ir pulando para a linha especifica da matriz que corresponde ao n�mero do c�digo
				codigolikert=atoi(c[auxlinha][auxcoluna]); // salva o novo valor da v�riavel codigolikert para continuar a verifica��o
			}
			frequencia[auxlinha-2][nivel-1]+=1;
			limite=c[auxlinha+1][auxcoluna][0]-'0';
			for(a=0;a<limite;a++){ // la�o de repeti��o para printar as escalas dispon�veis para determinada quest�o para o usu�rio
			printf("A Frequencia absoluta de %s � [%d]\n",c[auxlinha+2][auxcoluna],frequencia[auxlinha-2][auxcoluna]);
			auxcoluna++;
			}
			codigopergunta=0;
			codigolikert=0;
			auxlinha=0;
			auxcoluna=0;
			m++	;
		}
	m=1;		
	k++;
	}
	fclose(prespostas);
	fclose(pquestoes);
	printf("Pressione qualquer tecla para voltar ao menu principal: ");
	getchar();
}


void filtrocurso(){
	char respostas[4000][200];
	char contador[250];
	char curso[200]={'\0'};
	int acumulador=0;
	int questoes=0;
	int pessoas=0;
	int x=0,y=0,i=0,z=0,j=0;// numresposta refere-se ao numero de entrevistados
	FILE *prespostas,*pquestoes;
	pquestoes=fopen("questoes.txt","r");
	prespostas=fopen("respostas.txt","r");
	if (prespostas==NULL){
		printf("Arquivo n�o pode ser aberto");
		getchar();
		system("exit");
	}
	while(fgets(respostas[x],200,prespostas)!='\0'){//fgets(respostas[x],200,prespostas)!=NULL
		x++; //contador de linhas do arquivo respostas
	}
	while(fgets(contador,250,pquestoes) != '\0'){
		y++;
	}
	printf("Digite qual o curso que voc� deseja filtrar");
	printf("\nOBS:*Iniciais em letra mai�scula, sem acentua��o ou caracteres especiais. ex <Engenharia de Computacao> *\n");
	fflush(stdin);
	gets(curso);
	fflush(stdin);
	curso[strlen(curso)]='\n';
	for (i=0;i<x;i+=4){
		if(strcmp(curso,respostas[i])==0){
			pessoas++;// acumulador para saber quantos entrevistados pertencem a dado curso
			for(j=0;j<y;j+=2){//a incrementa��o de j � 2, com a finalidade de buscar apenas as respostas do usuarios, visto que o padr�o das sequencia de respostas � 'x y z' com um espa�o entre cada resposta
				if(respostas[i+3][j]!='\n' && respostas[i+3][j]!=' '){
					acumulador+=respostas[i+3][j]-'0';
					questoes++;
				}
			}
		}
			
	}
	system("cls");
	printf("Total de entrevistados que passaram pelo filtro: \n%d\n\n",pessoas);
	printf("Nome do curso Filtrado: \n");
	puts(curso);
	printf("\nEscore do curso filtrado \n%.2f\n\n",(float)acumulador/questoes);
	printf("Pressione qualquer tecla para voltar ao menu principal: ");
	getchar();
	fclose(prespostas);
}


float mediatotal(){
	int i=3;// v�riavel para controlar o loop e navegar nas linhas da matriz respons�vel pelas respostas, � inicializada em 3 pois � onde esta a primeira sequencia de respostas da matriz
	int j;// v�riavel para controlar o loop e navegar nas colunas da matriz respons�vel pelas respostas
	float acumulador=0;
	int questoes=0,pessoas=0;
	FILE *prespostas;
	prespostas=fopen("respostas.txt","r");
	if (prespostas==NULL){
		printf("Arquivo n�o pode ser aberto");
		getchar();
		system("exit");
	}
	FILE *pperguntas;
	pperguntas=fopen("questoes.txt","r");
	if (pperguntas==NULL){
		printf("Arquivo n�o pode ser aberto");
		getchar();
		system("exit");
	}
	int x=0;
	int y=0;
	char perguntas[200][200];
	while(fgets(perguntas[x],200,pperguntas)!=NULL){//fgets(respostas[x],200,prespostas)!=NULL
		//puts(perguntas[x]);
		x++; //contador de linhas do arquivo perguntas
	}
	char respostas [4000][200];
	while (fgets(respostas[y],sizeof(respostas),prespostas)!=NULL){
			y++; // contador de linhas do arquivo respostas 
	}
	for(i=3;i<y;i+=4){
		for(j=0;j<x;j+=2){
			if(respostas[i][j]!='\n' && respostas[i][j]!=' '){
			acumulador+=(respostas[i][j])-'0';
			questoes++; // contador para saber quantas vezes quest�es foram respondidas
			}
		}
		pessoas++; // contador de pessoas
	}
	printf("A quantidade de pessoas entrevistadas at� o momento � [%d]\n",pessoas);
	fclose(prespostas);
	fclose(pperguntas);
	return (float)acumulador/questoes;
}


void filtrosexo(){
	char respostas[4000][200];
	char sexo[100]={'\0'};
	char contador[250];
	int acumulador=0;
	int questoes=0;
	int pessoas=0;
	int x=0,y=0,i=0,z=0,j=0;
	FILE *prespostas,*pquestoes;
	prespostas=fopen("respostas.txt","r");
	pquestoes=fopen("questoes.txt","r");
	if (prespostas==NULL){
		printf("Arquivo n�o pode ser aberto");
		getchar();
		system("exit");
	}
	while(fgets(respostas[x],200,prespostas)!='\0'){//preenchendo a matriz com os dados do txt
		x++;
	}
	while(fgets(contador,250,pquestoes)!= '\0'){
		y++; //contador de perguntas para limitar o loop 
	}
	printf("%d VALOR DE X",x);
	printf("Digite qual o sexo que voc� deseja filtrar");
	printf("\nOBS:*Tudo min�sculo*\n");
	fflush(stdin);
	gets(sexo);
	fflush(stdin);
	sexo[strlen(sexo)]='\n';
	for (i=1;i<x;i+=4){
		if(strcmp(sexo,respostas[i])==0){
			pessoas++;// acumulador para saber quantos entrevistados pertencem a dado sexo
			for(j=0;j<y;j+=2){//a incrementa��o de j � 2, com a finalidade de buscar apenas as respostas do usuarios, visto que o padr�o das sequencia de respostas � 'x y z' com um espa�o entre cada resposta
				if(respostas[i+2][j]!='\n' && respostas[i+2][j]!=' '){
					acumulador+= (respostas[i+2][j])-'0';
					questoes++;
				}
			}
		}
			
	}
	system("cls");
	printf("Total de entrevistados que passaram pelo filtro: \n%d\n\n",pessoas);
	printf("Sexo Filtrado: \n");
	puts(sexo);
	printf("\nEscore do sexo filtrado \n%.2f\n\n",(float)acumulador/questoes);
	printf("Pressione qualquer tecla para voltar ao menu principal: ");
	getchar();
	fclose(prespostas);
	fclose(pquestoes);
}


void filtroidade(){
	char idade_min [5];
	char contador [250];
	char idade_max [5];
	char respostas [4000][200];
	int pessoas=0,acumulador=0,questoes=0;
	int x=0,i=0,j=0,y=0;
	FILE *pquestoes;
	FILE *prespostas;
	pquestoes=fopen("questoes.txt","r");
	prespostas=fopen("respostas.txt","r");
	if (prespostas==NULL){
		printf("Arquivo n�o pode ser aberto");
		getchar();
		system("exit");
	}
	while(fgets(respostas[x],200,prespostas)!='\0'){//preenchendo a matriz com os dados do txt
		x++; //contador de linhas do arquivo respostas
	}
	while(fgets(contador,250,pquestoes)!= '\0'){
		y++; //contador de perguntas para limitar o loop 
	}	
	printf("Digite a idade m�nima que deseja filtrar\n");
	fgets(idade_min,5,stdin);
	printf("Digite a idade m�xima que deseja filtrar\n");
	fgets(idade_max,5,stdin);
	/*printf("%d   %d",strlen(idade_min),strlen(idade_max);
	system("pause");*/
	for(i=2;i<x;i+=4){
		if(atoi(idade_min) <= atoi(respostas[i]) && atoi(respostas[i]) <= atoi(idade_max) ){
			pessoas++;
			for(j=0;j<y;j+=2){
				if(respostas[i+1][j]!='\n' && respostas[i+1][j]!=' '){
					printf("%d",(respostas[i+1][j])-'0');
					acumulador+= (respostas[i+1][j])-'0';
					questoes++;
				}
			}
			system("pause");
		}	
	}
	system("cls");
	printf("Total de entrevistados que passaram pelo filtro: \n%d\n\n",pessoas);
	printf("Faixa et�ria Filtrada: \n");
	printf("%d~%d",atoi(idade_min),atoi(idade_max));
	printf("\nEscore da faixa et�ria filtrada \n%.2f\n\n",(float)acumulador/questoes);
	printf("Pressione qualquer tecla para voltar ao menu principal: ");
	getchar();
	fclose(prespostas);
	fclose(pquestoes);
}
