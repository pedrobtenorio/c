#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

long long int inverso(long long int a, long long int m)
{
    a = a%m;
    for (int x=1; x<m; x++)
    {
       if ((a*x) % m == 1)//x é o inverso do numero
       {
         return x;
       }
    }
}

long long int primo(long long int n)
{
    int k, cont=0, x;
    x=sqrt(n);//melhorar velocidade do codigo
    for(k=1; k<=x; k++)
	{
		if(n%k==0)
		{
			cont++;
		}
	}
	if(cont>1||n<2)
	{
		return 0;
    }

  else
	{
		return 1;
	}
}

long long int mdc(long long int a, long long int b)
{
	if (b == 0)
    {
        return a;
    }
    else
    {
        return mdc(b, a%b);
    }
}

int code_decode(long long int M, long long int n, long long int e)
{
   long long int c=1;
    while(e>0)
    {
        //com base no peq. teo. de fermat, fazemos a exponenciação modular
        if(e % 2 ==1)
        {
            c=(c * M)%n;
        }
        M=(M*M)%n;
        e=e/2;
    }
    return c;

}

int main()
{
	FILE *msg; // criando a variável ponteiro para o arquivo
    long long int escolha, p, q, fi, n, e, d, i;
  	char mensagem[1000], alfabeto[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    num_invalido:
    printf("#Olá, esse é um programa para codificar e descodificar mensagens utilizando criptografia RSA\n#Escolha uma das opções\n#1: Gerar chave publica e privada\n#2: Criptografar\n#3: Descriptografar\n");
    scanf("%lld", &escolha);
    if(escolha==1)
    {
        primo_invalido:
        printf("#Digite 2 numeros primos:\n");
        scanf("%lld%lld", &p, &q);//2 primeiras chaves privadas
        if(!(primo(q)) || !(primo(p))|| p*q<26)
        {
            printf("#Um dos numeros não é valido (os numeros não são primos ou são muito pequenos)\n\n");
            goto primo_invalido;
        }
        n=p*q;//Primeira chave publica
        fi=(p-1)*(q-1);//so pra conta (anderson)
        expoente_invalido:
        printf("#Valor de φ: %lld\n#Digite um valor para o expoente (entre 1 e %lld e mdc de φ expoente é=1)\n", fi, fi);
        scanf("%lld", &e);
        if(mdc(e, fi)==1)
        {
            printf("#Expoente valido\n#Chaves feitas com sucesso\n");
        }
        else
        {
            printf("#Expoente invalido, digite outro\n\n");
            goto expoente_invalido;
        }
        // "e" eh a segunda chave publica
        d=inverso(e, fi); //ultima chave privada
        printf("#Chaves publicas (%lld %lld)\n#'p', 'q' e 'e' (%lld %lld %lld)\n", n, e, p, q, e);
        msg=fopen("Chaves Publicas.txt", "w");
        fprintf(msg, "%lld %lld", n, e);
        fclose(msg);
        escolhaerrada:
        printf("#Escolha o proximo passo.\n#1: Fechar o programa\n#2: Codificar a mensagem\n#3: Decodificar mensagem\n");
        scanf("%lld", &escolha);
        if(escolha==1)
        {
            goto final;
        }
        else if(escolha==2)
        {
            goto parte2;
        }
        else if(escolha==3)
        {
            goto parte3;
        }
        else
        {
            goto escolhaerrada;
        }

    }
    else if(escolha==2)
    {
        long long int descodificado[100], aux;
        parte2:
		printf("#Insira as chaves publicas(na ordem gerada)\n");
        scanf("%lld%lld", &n, &e);
        char lixo;
        scanf("%c", &lixo);
        printf("#Digite uma mensagem para ser criptografada.\n");
        scanf("%[^\n]", mensagem);
      	msg=fopen("MensagemCripto.txt", "w");
      	for(i=0; i<strlen(mensagem);i++)
        {
          mensagem[i]=toupper(mensagem[i]);
          for(aux = 0; aux<27; aux++)
          {
            if(mensagem[i]==alfabeto[aux])
            {
                descodificado[i]=aux;
                printf("%d ", code_decode(descodificado[i], n, e));
            	fprintf(msg, "%d ", code_decode(descodificado[i], n, e));
            }
          }

        }
        fclose(msg);
        printf("\n");
        escolhaerrada2:
        printf("#Escolha o proximo passo.\n#1: Fechar o programa\n#2: Decodificar mensagem.\n");
        scanf("%lld", &escolha);
        if(escolha==1)
        {
            goto final;
        }
        else if(escolha==2)
        {
            goto parte3;
        }
        else
        {
            goto escolhaerrada2;
        }
    }
    else if(escolha==3)
    {

		long long int codificado[500], aux;
        parte3:
		printf("#Insira 'p', 'q', e 'e' \n");
        scanf("%lld%lld%lld", &p, &q, &e);
        fi=(p-1)*(q-1);
        d=inverso(e, fi);
        n=p*q;
        char lixo;
        scanf("%c", &lixo);
        printf("#Digite uma mensagem para ser descriptografada.\n");
      	msg=fopen("MensagemDescripto.txt", "w");
        int tam=0;
      	for(;;)
        {
          scanf("%lld", &codificado[tam]);
          codificado[tam]=code_decode(codificado[tam], n, d); 
          tam++;
          if(getchar()=='\n')
          {
            for( i = 0; i < tam; i++)
            {
                for(aux = 0; aux<28; aux++)
                {
                    if(codificado[i]==aux)
                    {
                        printf("%c", alfabeto[aux]);
                        fprintf(msg, "%c", alfabeto[aux]);
                        break;
                    }

                }
            }
            break;
          }
        }
        fclose(msg);
        printf("\n");
        goto final;
    }
    else
    {
        printf("#Escolha invalida\n\n");
        goto num_invalido;
    }
    final:
    return 0;
}