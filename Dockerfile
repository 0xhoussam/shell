FROM ubuntu:latest

RUN apt update && apt install -y \
    git \
    vim \
    neovim \
    python3 \
    python3-pip \
    curl \
    wget \
    clang \
    gdb \
    lldb \
    valgrind \
    strace
    nasm \
    bear \
	ltrace


RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)" "" --unattended

RUN pip3 install norminette c-formatter-42
RUN chsh -s /bin/zsh

CMD ["/usr/bin/zsh"]