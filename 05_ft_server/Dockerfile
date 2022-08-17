FROM debian:buster
MAINTAINER jeujeon <jeujeon@student.42seoul.co.kr>

RUN	apt-get update && apt-get install -y \
	nginx \
	mariadb-server \
	php-mysql \
	php-mbstring \
	openssl \
	vim \
	wget \
	php7.3-fpm

COPY ./srcs/run.sh ./
COPY ./srcs/default ./tmp
COPY ./srcs/config.inc.php ./tmp
COPY ./srcs/wp-config.php ./tmp

EXPOSE 80
EXPOSE 443

CMD bash run.sh