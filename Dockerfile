FROM ubuntu:14.04

RUN apt-get update 
RUN apt-get -y install build-essential
RUN apt-get install check
