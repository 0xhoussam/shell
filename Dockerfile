FROM ubuntu:latest

RUN apt update && apt install -y \
    gcc \
    make \
    zsh

CMD ["/usr/bin/zsh"]