FROM qubo188612/ubuntu20.04:latest AS latest

COPY ./leaser_measurementexe /workspace/leaser

RUN sudo apt-get update  \
    && sudo apt-get -y install libopenni-dev \
    && sudo rm -rf /var/lib/apt/lists/* 
    
RUN sudo chmod -R 777 /workspace/leaser

WORKDIR /workspace/leaser

CMD ["/workspace/leaser/leaser_measurement.sh"]
