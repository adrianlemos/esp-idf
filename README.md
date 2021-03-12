# Framework de Desenvolvimento para IoT da Espressif

* [中文版](./README_CN.md) 
* [English](./README_en.md)

ESP-IDF é o framework de desenvolvimento oficial para a série de SOCs **ESP32** e o **ESP32-S** fornecida para Windows, Linux e macOS. 


# Desenvolvendo com ESP-IDF

## Configurando o ESP-IDF

Olhe o Guia de configuranção para instruções detalhadas de como configurar o ESP-IDF:

| Chip | Guia de primeiros passos para ESP-IDF |
|:----:|:----|
| <img src="docs/_static/chip-esp32.svg" height="85" alt="ESP32"> |  <ul><li>[Versão estável](https://docs.espressif.com/projects/esp-idf/en/stable/get-started/) </li><li>[Ultima versão (master branch)](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/) </li></ul> |
| <img src="docs/_static/chip-esp32-s2.svg" height="100" alt="ESP32-S2"> | <ul><li>[Ultima versão (master branch)](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s2/get-started/) </li></ul> |

**Nota:** Cada versão do ESP-IDF tem sua própria documentação. Consulte a seção [Versões](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/versions.html) para saber como encontrar a documentação e como verificar a versão específica do ESP-IDF.


### Forks fora do GitHub

ESP-IDF usa localizações relativas como suas URLs de submódulos ([.gitmodules](.gitmodules)). Então, eles se conectam ao GitHub. Se ESP-IDF for bifurcado para um repositório Git que não está no GitHub, você precisará executar o script [tools/set-submodules-to-github.sh](tools/set-submodules-to-github.sh) após fazer o clone do git. O script define URLs absolutos para todos os submódulos, permitindo que o comando `git submodule update --init --recursive` seja concluído. Se for clonar ESP-IDF do GitHub, esta etapa não é necessária.


## Encontrando um Projeto

Assim como o projeto [esp-idf-template](https://github.com/espressif/esp-idf-template) mencionado em Começando, ESP-IDF vem com alguns projetos de exemplo no diretório de [examplos](examples).

Depois de encontrar o projeto com o qual deseja trabalhar, mude para seu diretório e você pode configurá-lo e construí-lo.

Para iniciar seu próprio projeto com base em um exemplo, copie o diretório do projeto de exemplo para fora do diretório ESP-IDF.


# Referência Rápida

Consulte os links do guia de primeiros passos acima para obter um guia de configuração detalhado. Esta é uma referência rápida para comandos comuns ao se trabalhar com projetos ESP-IDF:

## Configuração do Ambiente de Compilação

(Consulte o guia de primeiros passos listado acima para obter uma lista completa das etapas necessárias com mais detalhes.)

* Instale as dependências de compilação do host mencionadas no guia de primeiros passos.
* Execute o script de instalação para configurar o ambiente de compilação. As opções incluem `install.bat` ou o `install.ps1` para Windows e `install.sh` ou `install.fish` para sistemas Unix.
* Execute o script de exportação no Windows (`export.bat`) ou o fonte no Unix (`source export.sh`) em cada ambiente antes de usar ESP-IDF.


## Configurando o Projeto

* `idf.py set-target <chip_name>` define o objetivo do projeto para `<chip_name>`. Execute `idf.py set-target` sem nenhum argumento para ver uma lista de destinos suportados.
* `idf.py menuconfig` abre um menu de configuração baseado em texto onde você pode configurar o projeto.

## Compilando o Projeto

`idf.py build`

... irá compilar o app, bootloader e gerar uma tabela de partição baseada na configuração.

## Gravando o Projeto

Quando a compilação terminar, ele irá imprimir uma linha de comando para usar no arquivo esptool.py para atualizar o chip. No entanto, você também pode fazer isso automaticamente executando:

`idf.py -p PORT flash`


Substitua PORT pelo nome da sua porta serial (como `COM3` no Windows, `/dev/ttyUSB0` no Linux ou `/dev/cu.usbserial-X` no MacOS. Se a opção `-p` for deixada de fora o idf.py tentará se conectar na primeira porta serial disponível.

Isso irá atualizar todo o projeto (app, bootloader e tabela de partição) para um novo chip. As configurações para a gravação da porta serial podem ser configuradas com `idf.py menuconfig`.

Você não precisa rodar o comando `idf.py build` antes de rodar o `idf.py flash`, `idf.py flash` irá reconstruir automaticamente qualquer coisa que precise.

## Visualizando a saída serial

O destino do `idf.py monitor` usa a ferramenta [idf_monitor tool](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/idf-monitor.html) para exibir a saída serial dos SoCs ESP32 ou ESP32-S. O idf_monitor também possui uma gama de recursos para decodificar  uma quebra na saída ou na interação com o dispositivo. [Verifique a página de documentação para obter detalhes](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/idf-monitor.html).

Saia do monitor digitando Ctrl-].

Para criar, atualizar e monitorar a saída em um passo, você pode executar:

`idf.py flash monitor`

## Compilando e Atualizando apenas o App

Após a gravação inicial, você pode querer apenas construir e atualizar apenas o seu app, não o bootloader e a tabela de partição:

* `idf.py app` - Contrói apenas o app.
* `idf.py app-flash` - Grava apenas o app.

`idf.py app-flash` irá reconstruir automaticamente o app se algum arquivo de origem for alterado.

(No desenvolvimento normal, não há nenhuma desvantagem em atualizar o bootloader e a tabela de partição a cada vez, se eles não tiverem mudado.)

## Apagando a Flash

O destino do arquivo `idf.py flash` não apaga todo o conteúdo da flash. No entanto, às vezes é útil definir o dispositivo de volta para um estado totalmente apagado, especialmente ao fazer alterações na tabela de partição ou atualizações de aplicativos OTA. Para apagar toda a flash, execute `idf.py erase_flash`.

Isso pode ser combinado com outros dispositivos, por exemplo, `idf.py -p PORT erase_flash flash` apagará tudo e então atualizará novamente o novo aplicativo, bootloader e tabela de partição.

## Começando em Português do Brasil

## Outras Fontes

* Documentação da ultima versão: https://docs.espressif.com/projects/esp-idf/. Este documento foi criado a partir do [Diretório docs](docs) deste repositório.

* O fórum [esp32.com forum](https://esp32.com/) é um lugar para fazer perguntas e encontrar recursos na comunidade.

* [Verifique a seção Problemas no github](https://github.com/espressif/esp-idf/issues) caso você encontrar um bug ou tiver uma solicitação de recurso. Verifique os problemas existentes antes de abrir um novo.

* Se você estiver interessado em contribuir para o ESP-IDF, consulte o [Guia de contribuições](https://docs.espressif.com/projects/esp-idf/en/latest/contribute/index.html)..


