FROM qubo188612/ubuntu20.04:opencvrosqtpclmodbus AS run

COPY ./myRos2test/install /workspace/myRos2test/install
COPY ./build-leaser_measurement-Replacement_for_Desktop_Qt_5_12_12_GCC_64bit-Release /workspace/leaser

WORKDIR /workspace/leaser

RUN sed -i '$c source /workspace/myRos2test/install/local_setup.sh' /home/linuxbrew/.bashrc

CMD [ "/workspace/leaser/leaser_measurement" ]
