/*******************************************************************************
Autor: Thiago Cardozo de Jesus
Componente Curricular: Algoritmos I
Concluido em: 25/12/2018
Declaro que este c�digo foi elaborado por mim de forma individual e n�o cont�m nenhum
trecho de c�digo de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e p�ginas ou documentos eletr�nicos da Internet. Qualquer trecho de c�digo
de outra autoria que n�o a minha est� destacado com uma cita��o para o autor e a fonte
do c�digo, e estou ciente que estes trechos n�o ser�o considerados para fins de avalia��o.
******************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
//Declara��o de Struct's
typedef struct{
	char codigo_projeto [8];
	char titulo [100];
	char area_conhecimento [35];
	char autor [50];
	char orientador [50];
	char coorientador [50];
	char data[15];
	char coautor [50];
}cadastro;
typedef struct{
	int status;
	char codigo_projeto [8];
	char titulo [100];
	float nota;
}subscrito;
//Declara��o dos Procedimentos

void new_prop(); //entrada de novas propostas
void avalie_prop(); //avalia��o das propostas
void grava_aprovados(subscrito*); //gravar as propostas aprovadas e gravar as propostas aprovadas ordenadas
void cancela_prop();// cancelar alguma proposta j� aprovada
void programa(); //apresenta a programa�ao da semana
void ordena_area_aprovados();
void apresenta_grade(subscrito *,int z); //apresenta a grade de horarios e as propostas para os dias de apresenta��o
//Declara��o das fun��es

subscrito *ordena_aprovados(subscrito *,int); //fun��o que ordenar as propostas por nota e retorna um vetor de struct
int gera_codigo(int);

int main(){
	system("cls");
	setlocale(LC_ALL,"Portuguese");
	system("color C");
	int menu;
	// Utiliza��o de menus para as funcionalidades
	printf("Digite a tecla da op��o desejada\n[1]Para Entrada de novas propostas\n[2]Avaliar as propostas computadas\n[3]Cancelamento de propostas\n[4]Apresenta��o do calend�rio de apresenta��es\n[5]Para Sair\n");
	scanf("%d",&menu);
	getchar();
	switch(menu){
		case 1:
			//fun��o
			system("cls");
			new_prop();
			main();
			break;
		case 2:
			//fun��o
			system("cls");
			avalie_prop();
			main();
			break;
		case 3:
			//fun��o
			system("cls");
			cancela_prop();
			main();
			break;
		case 4:
			//fun��o
			system("cls");
			programa();
			main();
			break;
		case 5:
			//fun��o
			exit(1);
			break;
	}
	return 0;
}
void new_prop(){
	system("cls");
	FILE* respostas;
	respostas=fopen("rpts.txt","a+");
	if(!respostas){
		printf("O Arquivo de grava��o n�o pode ser aberto");
	}
	int escolha_area=0; //vari�vel para armazenar a escolha do usu�rio em rela�ao a area de conhecimento
	int verific;// variavel para tratamento de erros na inser��o do autor e orientador
	int existe;// variavel responsavel por tratar a existencia ou n�o de coautores e coorientadores
	cadastro dados;// variavel struct para guardar os dados da proposta.
	char area_c[5];//variavel para guardar a area do conhecimento da proposta
	char contador_prop[250]={'\0'};//variavel para navegar no arquivo de respostas e descobrir quantas propostas j� foram computadas, a fim de gerar o c�digo padr�o. 
	int x=0;// vari�vel para contar as propostas.
	do{
		printf("Digite a tecla correspondente a qual a �rea de conhecimento a sua proposta se relaciona:");
		printf("\n1. Ci�ncias da Sa�de\n2. Ci�ncias Exatas\n3. Ci�ncias Agr�rias\n4. Engenharias\n5. Ci�ncias Sociais Aplicadas\n6. Ci�ncias Humanas\n7. Lingu�stica, Letras e Artes\n");
		scanf("%d",&escolha_area);
		fflush(stdin);
		if (escolha_area<1||escolha_area>7){
			printf("Escolha inv�lida");
			system ("pause");
			system ("cls");
		}
	}while(escolha_area<1||escolha_area>7);
	fprintf(respostas,"0%d",escolha_area);
	FILE* leiturar;
	leiturar=fopen("rpts.txt","r");
	if(!leiturar){
		printf("deu ruim");
	}
	x=gera_codigo(escolha_area); //atribui a x o valor do contador das propostas da determinada area
	fprintf(respostas,"0%d\n",x);
	printf("Digite o T�tulo do seu projeto:\n"); //bloco para a coleta de dados do projeto do usu�rio e grava��o no arquivo de respostas
	fgets(dados.titulo,100,stdin);
	fprintf(respostas,"%s",dados.titulo);
	switch(escolha_area){
		case 1:
			fprintf(respostas,"Ci�ncias da Sa�de\n");
			break;
		case 2:
			fprintf(respostas,"Ci�ncias Exatas\n");
			break;
		case 3:
			fprintf(respostas,"Ci�ncias Agr�rias\n");
			break;
		case 4:
			fprintf(respostas,"Engenharias\n");
			break;
		case 5:
			fprintf(respostas,"Ci�ncias Sociais Aplicadas\n");
			break;
		case 6:
			fprintf(respostas,"Ci�ncias Humanas\n");
			break;
		case 7:
			fprintf(respostas,"Ligu�stica, Letras e Artes\n");
			break;
	}
	do{
		verific=0;
		printf("Digite o nome autor do projeto:\n");
		gets(dados.autor);
		if(strlen(dados.autor)<3){
			verific=1;
			printf("\nNome do autor � obrigat�rio\n");
			system("pause");
			system("cls");	
		}
	}while(verific==1);
	fprintf(respostas,"%s\n",dados.autor);
	printf("Caso exista coautor do projeto, digite 1.\nSe n�o existir digite 0:\n");
	scanf("%d",&existe);
	fflush(stdin);
	switch(existe){
		case 1:
			printf("Digite o nome do coautor:\n");
			fgets(dados.coautor,50,stdin);
			fprintf(respostas,"%s",dados.coautor);
			break;
		default:
			fprintf(respostas,"INEXISTENTE\n");
			break;
	}
	do{
		verific=0;
		printf("Digite o nome do orientador do projeto:\n");
		gets(dados.orientador);
		if(strlen(dados.orientador)<3){
			verific=1;
			printf("\nNome do orientador � obrigat�rio\n");
			system("pause");
			system("cls");
		}
	}while(verific==1);
	fprintf(respostas,"%s\n",dados.orientador);
	printf("Caso exista coorientador do projeto, digite 1.\nSe n�o existir digite 0:\n");
	scanf("%d",&existe);
	getchar();
	switch(existe){
		case 1:
			printf("Digite o Nome do Coorientador:\n");
			fgets(dados.coorientador,50,stdin);
			fprintf(respostas,"%s",dados.coorientador);
			break;
		default:
			fprintf(respostas,"INEXISTENTE\n");
			break;
	} //fim da coleta de dados			
	printf("Sua Proposta foi submetida...\n");
	printf("O C�digo do seu projeto �: 0%d0%d\n",escolha_area,x);// exibi��o do c�digo do projeto para o usuario
	// verifica�a� para saber se deseja submeter uma nova pesquisa ou n�o
	system("pause");
	fclose(respostas);
	fclose(leiturar);
}
void avalie_prop(){
	int x=0; //responsavel pela contagem de entrevistados
	char contador_prop[100]={'\0'}; //vetor para auxiliar na contagem de propostas do arquivo
	FILE* leitura;
	leitura=fopen("rpts.txt","r"); //leitura do arquivo de propostas
	if(leitura=='\0'){ //tratamento de erro
		printf("Erro ao abrir o arquivo");
		printf("\nProvavelmente ainda n�o existe propostas cadastradas\n");
		system("pause");
		main();
	}
	char propostas[14][40]={'\0'}; //matriz din�mica para a visualiza��o das propostas do txt
	while(fgets(contador_prop,100,leitura)!='\0'){ //para saber quantas linhas  existem no arquivo txt
		x++;
	}
	x=x/7;// para saber quantas propostas existem no arquivo txt, divis�o por 7 por que � a quantidade de informa��es de cada proposta no arquivo rpts.txt
	if(x<1){//tratamento de erro caso nao exista propostas
		printf("Ainda n�o existe propostas cadastradas para serem avaliadas\n");
		system("pause");
		main();
	}
	subscrito *aprovados; //ponteiro que se tornar�, atrav�s da fun��o grava_aprovados/ordena_aprovados, um vetor de struct j� ordenado por nota
	
	printf("NUMERO DE PROPOSTAS :%d\n",x);
	rewind(leitura); //posicionar o ponteiro novamente no inicio do arquivo, para posterior grava��o na matriz
	int y=0,z=0;// responsavel por auxiliar na apresenta��o dos dados do txt 
	float nota;// variavel para guardar o valor da nota atribuida ao trabalho
	int avalie;// pra saber se a proposta foi aprovada ou rejeitada
	FILE *apr,*repr;// declara�ao de ponteiros de arquivo
	apr=fopen("aprovados.txt","a+"); //arquivo dos aprovados
	repr=fopen("reprovados.txt","a+");//arquivo dos reprovados
	
		for(z=0;z<x;z++){						//inicio do la�o for para a apresenta��o das propostas e seus dados
			for(y=0;y<7;y++){ // Pegando os dados da proposta numero "y" do arquivo 
			fgets(propostas[y],40,leitura);
			}
			for(y=0;y<7;y++){ // apresenta�ao dos dados da proposta numero "y" para o avaliador
				switch(y){ // para saber qual dado sera apresenta�ao atraves do valor de y
					case 0:
						printf("CODIGO: ");
						break;
					case 1:
						printf("TITULO: ");
						break;
					case 2:
						printf("�REA DE CONHECIMENTO: ");
						break;
					case 3:
						printf("AUTOR: ");
						break;
					case 4:
						printf("COAUTOR: ");
						break;
					case 5:
						printf("ORIENTADOR: ");
						break;
					case 6:
						printf("COORIENTADOR: ");
						break;
				}
				puts(propostas[y]); //imprime determinado dado da proposta "y"
			}
			printf("Avalie essa proposta:\n1-APROVADA\t\t2-REPROVADA\n");
			scanf("%d",&avalie); //avalia��o
			fflush(stdin);
			if(avalie==1){ //verifica�ao da avalia��o
				printf("Digite a nota para esse projeto de < 0~10 >: ");
				scanf("%f",&nota);
				fflush(stdin);
				fprintf(apr,"1\n");
				fprintf(apr,"%s",propostas[0]);
				fprintf(apr,"%s",propostas[1]);
				fprintf(apr,"%.1f\n",nota);
			}
			else{
				printf("Digite a nota para esse projeto: ");
				scanf("%f",&nota);
				fflush(stdin);
				fprintf(repr,"REPROVADO\n");
				fputs(propostas[0],repr);
				fputs(propostas[1],repr);
				fprintf(repr,"%.1f\n",nota);
			}
			system("cls");
	}		//fim do la�o for
	printf("Todas as propostas foram avaliadas\n");
	FILE *apagar_dados;
	apagar_dados=fopen("rpts.txt","w");	//para limpar os dados do arquivo de propostqas, j� que elas j� foram avaliadas
	fclose(apr);
	fclose(repr);
	fclose(leitura);
	fclose(apagar_dados);
	grava_aprovados(aprovados); //grava as propostas no vetor de struct (aprovados) e dentro de grava_aprovados possui um proccedimento para ordena o mesmo vetor e jogar num arquivo txt
	system("pause");
}
void grava_aprovados(subscrito *aprovados){ //parametro vetor de struct subscrito
	FILE *apr; 
	FILE *apr_ord;
	apr=fopen("aprovados.txt","r"); //abertura do arquivo dos aprovados para leitura
	int x=0;
	int y=0; //variavel para controlar o la�o for para preencher o vetor din�mico com as propostas aprovadas
	char contador[100];//auxilia no processo de contagem de propostas
	char nota[6]; //string que guardar� o valor da nota do projeto para posterior convers�o em float
	char status[3]; // string que guardar� o valor do status do projeto para posterior convers�o
	while(fgets(contador,100,apr)!='\0'){ //para saber quantas linhas  existem no arquivo txt
	x++;
	}
	x=x/4; //divis�o por 4 para saber quantas propostas est�o no txt, divide-se por 4 pois � a quantidade de dados de cada proposta no arquivo aprovados.txt
	if(x<=0){//tratamento de erro
		printf("N�o existem propostas para serem ordenadas");
		return;
	}
	rewind(apr);//pq o ponteiro est� no final do arquivo. Para reposicionar no inicio
	aprovados =(subscrito *) malloc(x*sizeof(subscrito)); //aloca�ao do vetor, vetor possuira [x] indices, sendo x a quantidade de propostas presentes no aprovados.txt
	if(aprovados==NULL){ //tratamento de erro
		printf("Erro de aloca��o");
		return ;
	}
	for(y=0;y<x;y++){ //grava��o dos dados do txt nos respectivos elementos do vetor
		fgets(status,3,apr);
		fgets(aprovados[y].codigo_projeto,8,apr);
		fgets(aprovados[y].titulo,100,apr);
		fgets(nota,6,apr);
		nota[strlen(nota)]='\0'; //para tirar o \n da string com a finalidade de converter para float
		status[strlen(status)]='\0';// tirar o zn da string com a finalidade de converter para int
		aprovados[y].status=atoi(status);
		aprovados[y].nota=atof(nota);
	}//fim da grava��o dos dados, todas as propostas foram gravadas no vetor
	aprovados=ordena_aprovados(aprovados,x); // ordena��o do vetor por nota
	apr_ord=fopen("aprovados_ordenados.txt","w"); //abertura de arquivo para escrita
	for(y=0;y<x;y++){ //escrita das propostas ordenadas por nota no arquivo aprovados_ordenados
		fprintf(apr_ord,"%d\n",aprovados[y].status);
		fprintf(apr_ord,"%s",aprovados[y].codigo_projeto);
		fprintf(apr_ord,"%s",aprovados[y].titulo);
		fprintf(apr_ord,"%.1f\n",aprovados[y].nota);
	}
	free(aprovados);
	fclose(apr);
	fclose(apr_ord);
}
subscrito* ordena_aprovados(subscrito *vetor, int TAM){
	int i=0,j=0; // navegaram no vetor para o algoritmo orden�-lo
	int maior; //guardaram a posi��o da propostas com maior nota para ser colocada no inicio
	subscrito aux; //guardaram o valor da nota que tera sua posi��o trocada com o maior, para n�o perder a referencia
	for (i=0;i<TAM;i++){
    	maior=i; //atribui��o do valor de i para maior, pois depois de cada repeti��o um elemento do vetor j� estar� ordenado
    	for (j=(i+1);j<TAM;j++){
			if(vetor[j].nota>vetor[maior].nota){
        		maior=j;//guarda o indice da proposta com maior nota
        	}
    	}
    	if (vetor[i].nota!=vetor[maior].nota){
    		aux=vetor[i]; //salva o elemento da posi��o em que ficara o maior elemento da repeti��o
    		vetor[i]=vetor[maior]; //coloca a proposta com maior nota da repeti��o na posi��o i
    		vetor[maior]=aux; //troca de lugar a proposta com maior nota, vetor[maior representa a antiga posi��o da proposta com maior nota
    	}
  	}
	return vetor; //retorna vetor ja ordenado
}
void cancela_prop(){ //lembrete  *****comentar	
	int x=0,y;
	char contador[100];
	char status[3];
	char codigo_proposta[8];
	char nota[6];
	subscrito *propostas;
	FILE *prop;
	prop= fopen("aprovados_ordenados.txt","r");
	printf("Digite o c�digo da proposta que deseja cancelar\n");
	fgets(codigo_proposta,8,stdin);
	codigo_proposta[strlen(codigo_proposta)]='\0';
	while(fgets(contador,100,prop)!='\0'){
		x++;
	}
	x=x/4;
	rewind(prop);
	propostas=(subscrito*)malloc(x*sizeof(subscrito));
	for(y=0;y<x;y++){ //gravar os dados do txt no vetor
		fgets(status,3,prop);
		fgets(propostas[y].codigo_projeto,8,prop);
		fgets(propostas[y].titulo,100,prop);
		fgets(nota,6,prop);
		nota[strlen(nota)]='\0'; //para tirar o \n da string com a finalidade de converter para float
		status[strlen(status)]='\0';// tirar o \n da string com a finalidade de converter para int
		propostas[y].status=atoi(status);
		propostas[y].nota=atof(nota);	
	}
	int verific=1; //para saber se a proposta foi encontrada ou n�o
	for(y=0;y<x;y++){
		if(strcmp(codigo_proposta,propostas[y].codigo_projeto)== 0){
			propostas[y].status = 2;
			verific=0; //flag para representar a proposta encontrada
			break;
		}
	}
	if(verific==1){
		printf("Proposta n�o encontrada\n");
		system("pause");
		main();
	}
	FILE *preencher_cancelado;
	preencher_cancelado=fopen("aprovados_ordenados.txt","w"); //sobrescreve o arquivo com a determinada proposta com status '2',,status==1 (aprovado e ordenado por nota) status==2 (cancelado) status == 3 (aprovado e ordenado por area e nota) 
	for(y=0;y<x;y++){
		fprintf(preencher_cancelado,"%d\n",propostas[y].status);
		fprintf(preencher_cancelado,"%s",propostas[y].codigo_projeto);
		fprintf(preencher_cancelado,"%s",propostas[y].titulo);
		fprintf(preencher_cancelado,"%.1f\n",propostas[y].nota);
	}
	printf("\nProposta Cancelada\n");
	system("\npause");
	system("cls");
	free(propostas);
	fclose(preencher_cancelado);
	fclose(prop);
}
int gera_codigo(int area){ //parametro de entrada � a area de conhecimento que o usuario digitar, ser� utilizada para acessar a respectiva linha da matriz para a gera�ao do codigo
	FILE *cod;
	cod=fopen("codigos.txt","r"); //abre o arquivo que possui a contagem de codigos para a leitura
	char matriz[7][4];// matriz para pegar o valor dos contadores
	char conversor[3]={'\0'};
	int count=0;
	int x=0;
	for(x=0;x<7;x++)
		fgets(matriz[x],4,cod);
	fclose(cod);
	/*pega o conteudo das 3 colunas da matriz,sendo ele coluna[0] = o valor do contador,coluna[1]= \n, coluna[2] = \0 */
	conversor[0]=matriz[area-1][0];
	conversor[1]=matriz[area-1][1];
	conversor[2]=matriz[area-1][2];
	conversor[strlen(conversor)]='\0'; //retirada do \n para a convers�o com atoi
	count = atoi(conversor); //convers�o para inteiro para incrementa�ao
	snprintf(matriz[area-1],4,"%d",count+1); //incrementa��o do contador e grava��o na matriz
	system("cls");
	matriz[area-1][ strlen(matriz[area-1]) ]='\n'; // colocada do \n novamente na matriz para ser escrito no arquivo 
	matriz[area-1][ strlen(matriz[area-1]) ]='\0'; // colocada do \0 novamente na matriz para ser escrito no arquivo
	FILE* atualiza;
	atualiza=fopen("codigos.txt","w");
	for(x=0;x<7;x++)//atualiza o arquivo com a contagem j� incrementada
		fprintf(atualiza,"%s",matriz[x]);
	fclose(atualiza);
	return count+1; //retorna o contador j� incrementado
}
void programa(){
	ordena_area_aprovados();
	int x=0,z=0,z2=0;
	char contador[100];
	FILE *leitura_aprovados;
	leitura_aprovados=fopen("aprovados_ordenados.txt","r");
	while(fgets(contador,100,leitura_aprovados)!='\0'){
		x++;
	}
	x=x/4; //quantidade total de aprovados
	if(x==1){
		z=1;
	}
	else{
		if(x%2==0){//para saber se os dias ter�o a mesma quantidade de propostas ou n�o
			z= x/2;
			z2= x/2;
		}
		else{
		z= x/2+1; //quantidade de aprovados distruibuidos pelo dia um de apresenta��es
		z2=(x/2); //quantidade de aprovados distribuidos pelo dia dois de apresenta��es
		}
	}
	fclose(leitura_aprovados);
	FILE *leitura_bin;
	leitura_bin=fopen("prog.bin","rb");
	subscrito *dia_1,*dia_2; //vetores din�micos para os dias de apresenta��es
	dia_1=(subscrito *) malloc(z*sizeof(subscrito));
	dia_2=(subscrito *) malloc(z*sizeof(subscrito));
	fread(dia_1,sizeof(subscrito),z,leitura_bin);
	fread(dia_2,sizeof(subscrito),z2,leitura_bin);
	int y=0;
	printf("PRIMEIRO DIA DE APRESENTA��ES\n----------------------------\n");
	apresenta_grade(dia_1,z);
	system("pause");
	system("cls");
	if(x>1){ // s� sera exibido o segundo dia de apresenta�oes de x for maior que 1, pois se x for 1 existe apenas uma apresenta�ao
	printf("SEGUNDO DIA DE APRESENTA��ES\n----------------------------\n");
	apresenta_grade(dia_2,z2);
	system("pause");
	system("cls");
	}
	free(dia_1);
	free(dia_2);
	fclose(leitura_bin);
}
void ordena_area_aprovados(){
	int x=0;
	int y=0;
	char contador[100];
	char nota[6];
	char status[3];
	subscrito *propostas;
	FILE* apr;	
	apr=fopen("aprovados_ordenados.txt","r");
	if(apr==NULL){
		printf("erro ao abrir o arquivo\n");
		printf("Provavelmente n�o existe projetos cadastrados e avaliados\n");
		system("pause");
		main();
	}
	while(fgets(contador,100,apr)!='\0'){
		x++;
	}
	x=x/4; //conta quantas propostas tem para a aloca��o de memoria
	if(x<=0){ //tratamento de erro
		printf("Ainda n�o existem propostas avaliadas para serem alocadas nos dias de apresenta��es\n");
		system("pause");
		system("cls");
		main();
	}
	rewind(apr); //reposiciona o ponteiro para o inicio do arquivo
	propostas=(subscrito*) malloc(x*sizeof(subscrito)); //aloca��o de memoria para posterior grava�ao dos dados no vetor de struct
	if(propostas==NULL){//verifica o sucesso da aloca�ao
		printf("erro de aloca�ao");
		exit(1);
	}
	for(y=0;y<x;y++){
		fgets(status,3,apr);
		fgets(propostas[y].codigo_projeto,8,apr);
		fgets(propostas[y].titulo,100,apr);
		fgets(nota,6,apr);
		status[strlen(status)]='\0';
		nota[strlen(nota)]='\0';
		propostas[y].status=atoi(status);
		propostas[y].nota=atof(nota);		
	}
	int z=0;
	int j=0;
	char AREA = '1';
	subscrito aux;
	int aux2=0;
	for(y=0;y<x;y++){
		for(j=0;j<x;j++){
			if(propostas[j].status == 1){
				if(propostas[j].codigo_projeto[1]==AREA){
					propostas[j].status=3;
					aux=propostas[z];
					propostas[z]=propostas[j];
					propostas[j]=aux;		
					z++;
				}
				AREA++; //para a alterna�ao das areas de conhecimento
				if(AREA >= '8'){//para limitar ate 7
					AREA = '1';
				}
			}
		}
	}
	FILE *escrita_bin;
	escrita_bin=fopen("prog.bin","wb");
	fwrite(propostas,sizeof(subscrito),x,escrita_bin);
	free(propostas);
	fclose(escrita_bin);
	fclose(apr);
}
void apresenta_grade(subscrito *vetor,int z){
	int y=0;// variavel para auxiliar a navegar no vetor de struct
	int j=0; // variavel para controlar a quantidade de apresenta��es por dia, limitada a 32, e auxiliar na apresenta��o dos horarios 
	while(y<z){ //inicio do loop para aparesentar a grade de horarios
		if(vetor[y].status != 2 && j<32){ //inicio da verifica�ao do projeto e area de conhecimento do mesmo
			printf("TITULO: ");
			vetor[y].titulo[strlen(vetor[y].titulo)-1]='\0';
			puts(vetor[y].titulo);
			printf("�REA DE CONHECIMENTO: ");
			switch(vetor[y].codigo_projeto[1]){
				case '1':
					printf("Ci�ncias da Sa�de\n");
					break;
				case '2':
					printf("Ci�ncias Exatas\n");
					break;
				case '3':
					printf("Ci�ncias Agr�rias\n");
					break;
				case '4':
					printf("Engenharias\n");
					break;
				case '5':
					printf("Ci�ncias Sociais Aplicadas\n");
					break;
				case '6':
					printf("Ci�ncias Humanas\n");
					break;
				case '7':
					printf("Ligu�stica, Letras e Artes\n");
					break;
			}
			printf("HORARIO: ");
			switch(j){ //inicio da verifica��o dos horarios
				case 0:
					printf("08:00\n");
					break;
				case 1:
					printf("08:15\n");
					break;
				case 2:
					printf("08:30\n");
					break;
				case 3:
					printf("08:45\n");
					break;
				case 4:
					printf("09:00\n");
					break;
				case 5:
					printf("09:15\n");
					break;
				case 6:
					printf("09:30\n");
					break;
				case 7:
					printf("09:45\n");
					break;
				case 8:
					printf("10:00\n");
					break;
				case 9:
					printf("10:15\n");
					break;
				case 10:
					printf("10:30\n");
					break;
				case 11:
					printf("10:45\n");
					break;
				case 12:
					printf("11:00\n");
					break;
				case 13:
					printf("11:15\n");
					break;
				case 14:
					printf("11:30\n");
					break;
				case 15:
					printf("11:45\n");
					break;
				case 16:
					printf("14:00\n");
					break;
				case 17:
					printf("14:15\n");
					break;
				case 18:
					printf("14:30\n");
					break;
				case 19:
					printf("14:45\n");
					break;
				case 20:
					printf("15:00\n");
					break;
				case 21:
					printf("15:15\n");
					break;
				case 22:
					printf("15:30\n");
					break;
				case 23:
					printf("15:45\n");
					break;
				case 24:
					printf("16:00\n");
					break;
				case 25:
					printf("16:15\n");
					break;
				case 26:
					printf("16:30\n");
					break;
				case 27:
					printf("16:45\n");
					break;
				case 28:
					printf("17:00\n");
					break;
				case 29:
					printf("17:15\n");
					break;
				case 30:
					printf("17:30\n");
					break;
				case 31:
					printf("17:45\n");
					break;
			} //final da verifica��o dos horarios
			printf("\n");
		j++; // incrementa�ao do j para apresentar o proximo horario na proxima repeti�ao do loop
		}//final da verifica��o do projeto
		y++;
	}//fim do loop
}
