FROM ubuntu:latest

WORKDIR /app

RUN apt-get update 

RUN apt-get install -y curl wget tar net-tools

EXPOSE 8081
EXPOSE 8082

RUN wget -c https://releases.jfrog.io/artifactory/artifactory-pro/org/artifactory/pro/jfrog-artifactory-pro/[RELEASE]/jfrog-artifactory-pro-[RELEASE]-linux.tar.gz -O temp.tar.gz

RUN tar -xvzf temp.tar.gz --strip-components 1

CMD ["/app/app/bin/artifactoryctl", "start"]
