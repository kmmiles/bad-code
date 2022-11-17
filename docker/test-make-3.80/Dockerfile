FROM debian:bullseye

RUN set -ex; \
  export DEBIAN_FRONTEND=noninteractive; \
  export DEBCONF_NONINTERACTIVE_SEEN=true; \
  echo 'tzdata tzdata/Areas select Etc' | debconf-set-selections; \
  echo 'tzdata tzdata/Zones/Etc select UTC' | debconf-set-selections && \
  apt-get update -y && \
  apt-get upgrade -y && \
  apt-get install -qqy --no-install-recommends \
    software-properties-common \
    ca-certificates \
    build-essential \
    make \
    gcc \
    wget

RUN set -ex; \
  wget -nc https://ftp.gnu.org/pub/gnu/make/make-3.80.tar.gz

RUN set -ex; \
  wget -nc https://ftp.gnu.org/pub/gnu/make/make-3.80.tar.gz && \
  gzip -cd make-3.80.tar.gz | tar xvf - && \
  cd make-3.80 && ./configure --prefix=$(pwd) && \
  make

