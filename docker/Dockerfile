FROM ubuntu:18.04
RUN apt-get update && apt-get install gdb vim make gcc g++ libssl-dev -y

COPY cmake-3.16.4.tar.gz /tmp/
RUN cd /tmp/ && tar -xzf ./cmake-3.16.4.tar.gz  && cd cmake-3.16.4 && ./bootstrap 
RUN cd /tmp/cmake-3.16.4 && make -j6 && make install

RUN rm -rf /var/lib/apt/lists*

