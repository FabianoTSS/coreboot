# Use uma imagem base com Ubuntu
FROM ubuntu:20.04

# Instalar dependências do Coreboot
RUN apt-get update && apt-get install -y \
    build-essential \
    git \
    g++ \
    python3 \
    python3-pip \
    python3-setuptools \
    libncurses5-dev \
    libssl-dev \
    uuid-dev \
    iasl \
    xz-utils \
    && rm -rf /var/lib/apt/lists/*

# Definir diretório de trabalho
WORKDIR /coreboot

# Baixar dependências do Coreboot
RUN make crossgcc

# Definir o comando para iniciar o ambiente
CMD ["/bin/bash"]
