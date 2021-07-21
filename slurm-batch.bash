#!/bin/bash 

#SBATCH -J MOOSE     # job name
#SBATCH -o log_slurm.o%j  # output and error file name (%j expands to jobID)
#SBATCH -n 28              # total number of tasks requested
#SBATCH -N 1 # cpus to allocate per task
#SBATCH -p shortq           # queue (partition) -- defq, eduq, gpuq, shortq
###SBATCH --exclusive
#SBATCH -t 12:00:00       # run time (hh:mm:ss) - 12.0 hours in this example
# Generally needed modules:
module load slurm
. ~/miniconda3/etc/profile.d/conda.sh
conda activate moose

#module load intel/mk1
#module load intel/mpi
#module load moose-framework/moose/gcc
## Example module loads for other software:
# module load vasp
# module load python/intel/3.5
# module load lammps
#module load tutor

# Execute the program:
./fecrco-opt -i FeCrCo.i 

## Some examples:
# mpirun vasp_std
# mpirun lmp_cpu -v x 32 -v y 32 -v z 32 -v t 100 < in.lj
# mpirun python3 script.py

# Exit if mpirun errored:
status=$?
if [ $status -ne 0 ]; then
    exit $status
fi
# Do some post processing.
