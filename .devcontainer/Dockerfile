# Use a imagem base do Ubuntu 16.04
FROM ubuntu:16.04

# Defina o diretório de trabalho
WORKDIR /workspace

# Instale as dependências necessárias
RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y \
    curl \
    git \
    build-essential \
    python3 \
    bison \
    flex \
    libncurses5-dev \
    wget \
    zlib1g-dev \
    gawk \
    libssl-dev \
    gcc-multilib \
    g++-multilib \
    doxygen \
    iasl \
    uuid-dev \
    liblzma-dev \
    libpci-dev \
    clang \
    bc \
    libtool \
    autoconf \
    automake \
    make \
    cmake \
    libncurses5-dev \
    libncursesw5-dev \
    nasm && \
    apt-get clean

# Instale o cbfstool (se necessário)
RUN git clone https://review.coreboot.org/coreboot.git /workspace/coreboot && \
    cd /workspace/coreboot/util/cbfstool && \
    make

# Defina o diretório de trabalho final
WORKDIR /workspace/coreboot

# Comando padrão (bash ou qualquer outro comando que você prefira)
CMD ["bash"]
