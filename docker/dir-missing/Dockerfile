FROM debian:bullseye

RUN set -ex; \
  groupadd -f "solr" && \
  useradd -m "solr" -g "solr"

RUN set -ex; \
  mkdir -v -p /var/solr/data && \
  chown solr:solr /var/solr/data && \
  echo "hello" > /hello.txt && \
  ls /var/solr > /test1.txt && \
  ls /var/solr > /test2.txt
