import glob
import os

cmake_sourcelist = "target_sources(MyGame.out PRIVATE"

for file in glob.glob("./src/*.cpp"):
    cmake_sourcelist += f"\n {file}"

cmake_sourcelist += ")"

if (glob.glob("./sourcelist.cmake")):
       os.remove("./sourcelist.cmake")

with open("./sourcelist.cmake", 'w') as file:
    file.write(cmake_sourcelist)

print("Sourcelist succesfully created")
