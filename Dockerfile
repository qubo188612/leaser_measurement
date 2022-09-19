FROM qubo188612/ubuntu20.04:opencv4.2 AS opencv
FROM qubo188612/ubuntu20.04:opencvrosqtpcl AS run

COPY --from=opencv /opt/opencv4.2 /lib/x86_64-linux-gnu

COPY ./myRos2test/install /workspace/myRos2test/install
COPY ./build-leaser_measurement-Replacement_for_Desktop_Qt_5_12_12_GCC_64bit-Release /workspace/leaser

RUN sudo apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && sudo apt-get -y install --no-install-recommends  \
    fonts-noto-cjk \
    qt5* \
    libtbb2 \
    libopenexr-dev \
    libgdcm-tools \
    libgdal-dev \
    libavcodec-dev \
    && sudo rm -rf /var/lib/apt/lists/*
    
RUN sudo chmod -R 777 /workspace/leaser

WORKDIR /workspace/leaser

RUN sed -i '$c source /workspace/myRos2test/install/local_setup.sh' /home/linuxbrew/.bashrc

CMD [ "/workspace/leaser/leaser_measurement" ]
