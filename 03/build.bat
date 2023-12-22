
md build
pushd build
cl -Zi ../03p1.cpp User32.lib
cl -Zi ../03p2.cpp User32.lib
popd
