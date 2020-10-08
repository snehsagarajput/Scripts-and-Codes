import pkg_resources
from subprocess import call

packages = [dist.project_name for dist in pkg_resources.working_set]
print("Total Packages Found : "+str(len(packages))+"\n\n")
for i in range(len(packages)):
    print("Updating : "+str(packages[i]))
    call("pip install --upgrade " + ' '.join([packages[i]]), shell=True)
    print("DONE!!!! "+ str(len(packages)-i-1)+" left\n\n")
print("<<<<<<<<All DONE>>>>>>>>>")
