🚀 Protetor de Tela Animado em C com GLUT
Este projeto é uma simulação simples de um protetor de tela (screensaver), desenvolvido em C e utilizando a biblioteca gráfica GLUT (OpenGL Utility Toolkit). O objetivo é animar um quadrado que se move continuamente pela janela, reagindo de forma interativa a colisões com as bordas.

✨ O que o Projeto Faz
A animação principal é centrada em um quadrado que possui o seguinte comportamento:

  1. Movimento Contínuo: O quadrado se move de forma diagonal e constante pela janela.

  2. Detecção de Colisão: Ao atingir qualquer uma das quatro bordas da tela, ele inverte sua direção (ricochete).

  3. Feedback Visual de Colisão: A cada colisão, o quadrado exibe duas alterações visuais:
    - Mudança de Cor: Sua cor é alterada para uma nova cor aleatória (RGB).
    - Crescimento Progressivo: Seu tamanho é aumentado ligeiramente a cada colisão, até atingir um tamanho máximo predefinido (MAX_SIZE).

⚙️ Detalhes da Implementação
  1. Desenvolvimento: O projeto foi desenvolvido no ambiente Dev-C++ (mas o código é em C puro).

  2. Animação: A animação e a lógica de movimento são controladas pela função timer da GLUT, que garante a atualização constante e fluida do estado do objeto. O intervalo de 10ms (TIMER_INTERVAL) define a velocidade da animação.

  3. Gráficos:
    - GLUT e OpenGL: Utiliza as funções básicas do OpenGL para desenho (glBegin(GL_QUADS)) e a gluOrtho2D na função reshape para configurar um sistema de coordenadas 2D que mapeia pixels diretamente para as dimensões da janela.
    - Lógica de Colisão: A função handleCollision gerencia a mudança de direção, a alteração de cor (generateRandomColor), e o aumento de tamanho (currentSize = fmin(...)).

Este projeto é um excelente ponto de partida para entender os fundamentos da animação 2D, detecção de colisão e o uso do pipeline de eventos e callbacks da biblioteca GLUT.

🔧 Configuração Rápida da freeglut (Dev-C++)
Para compilar este projeto, você precisará da biblioteca freeglut configurada no seu ambiente Dev-C++ (MinGW).

Siga estas três etapas rápidas, copiando os arquivos da pasta freeglut (presente neste repositório) para as pastas correspondentes do seu Dev-C++:

  1. Copiar Arquivos da Biblioteca
    Copie os arquivos necessários da pasta de instalação da freeglut para o seu compilador MinGW (localizado, tipicamente, dentro da pasta do Dev-C++):

| Conteúdo a Copiar | De (na pasta `freeglut` do repositório) | Para (no seu Dev-C++) |
| :--- | :--- | :--- |
| Pasta **`GL`** | `freeglut/include/` | `[...]\MinGW64\include\` |
| Arquivos **`.a`** | `freeglut/lib/` | `[...]\MinGW64\lib\` |
| Arquivo **`freeglut.dll`** | `freeglut/bin/` | `[...]\MinGW64\bin\` |

  2. Configurar o Linker
    Você deve dizer ao Dev-C++ quais bibliotecas usar durante a compilação:
      - No Dev-C++, vá em "Project" → "Project Options".
      - Na aba "Parameters", insira as seguintes flags na seção Linker:
```
-lfreeglut
-lopengl32
-lglu32
```

Após esses passos, o projeto deve compilar e rodar corretamente.
