# OmniDB: Towards Portable and Efficient Query Processing on Parallel CPU/GPU Architectures #

## Introduction ##
Driven by the rapid hardware development of parallel
CPU/GPU architectures, we have witnessed emerging relational query processing techniques and implementations on those parallel architectures. However, most of those implementations are not portable across different architectures, because they are usually developed from scratch and target at a specific architecture. This paper proposes a kernel-adapter based design (OmniDB), a portable yet efficient query processor on parallel CPU/GPU architectures. OmniDB attempts to develop an extensible query processing kernel (qKernel) based on an abstract model for parallel architectures, and to leverage an architecturespecific layer (adapter) to make qKernel be aware of the target architecture. The goal of OmniDB is to maximize the common functionality in qKernel so that the development and maintenance efforts for adapters are minimized cross different architectures.

## Platform ##
  * **Hardware:** AMD APU A8-3870k, Intel Xeon E5506, ATI Firepro V7800, NVIDIA Quadro 5000
  * **Software:** Windows OS 8, Microsoft Visual Studio 2010, OpenCL 1.2, C/C++

## Experiment Dataset ##
  * To appear soon

## Project News ##
  * [2013-07-09] OmniDB is now on Google Code.
  * [2013-08-27] OmniDB will be demonstrated in VLDB 2013, Italy.

## Publication ##
  * Shuhao Zhang, Jiong He, Bingsheng He, Mian Lu. OmniDB: Towards Portable and Efficient Query Processing on Parallel CPU/GPU Architectures. In VLDB (demo track), 2013.

**_For the version with demo setup section, click [HERE](https://docs.google.com/file/d/0BxH2rGzkd1xHeXhrdzRDRmlpb2c/edit?usp=sharing)._**

## Copyright ##
_OmniDB is developed by Shuhao Zhang and Jiong He under the supervision of Bingsheng He._

_E-mail: tony\_zhang AT live DOT com DOT sg_