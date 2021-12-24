PyBind11
===================

Desc
---------------------------
import cpp to python

Env-setup-python39
---------------------------
IDE
~~~~~~~~~~~~~~~~
 - vs 2017
 - vscode

Python
~~~~~~~~~~~~~~~~
Down python v3.9

[A] Install pybind11
~~~~~~~~~~~~~~~~~~~~~~~~~~
.. code::

   pip install pybind11

[B] Down pybind11
~~~~~~~~~~~~~~~~~~~~~~~~~~
.. code::

    git clone https://github.com/pybind/pybind11.git

| So you can do A or B.

| Then, you need create cpp project to import pypackage, and create py file to use the package.

import python package form cpp[vs 2017]
-----------------------------------------
cpp project, config properties
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
- general
    
    - target extension: .pyd
    - configuration type: .dll

- vc++

    - include: python/include; pybind11/include;
    - lib: python/libs

- linker

    - input: python39.lib

output
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
- .lib 
- .pyd

| maybe need copy dll to *python/* and *python/DLLS/*

sample
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code::

    #include <pybind11/pybind11.h>
    #include <pybind11/stl.h>
    #include <pybind11/functional.h>
    namespace py = pybind11;

    class Base{
    public:
        virtual bool run() = 0;
        std::function<int(std::vector<int>)> m_call;
    };

    class PyBase : public Base{
    public:
        using Base::Base;
        bool run() override {
            PYBIND11_OVERRIDE_PURE(bool, Base, run,);
            printf("PyBase run\n");
        }
    };

    PYBIND11_MODULE(ProPyCPP, m) {
	m.doc() = "pybind11 example module";

	py::class_<Base, PyBase>(m, "Base")
		.def(py::init<>())
		.def_readwrite("call", &Base::m_call)
		.def("run", &Base::run);
    }

python use the package[vs code]
------------------------------------------

.. code::

    import ProPyCPP as pro

    def caller(datas)->int:
        ret = 0
        for one in datas:
            ret += one
        return ret

    class PySuper(pro.Base):
        def __init__(self):
            super().__init__()
    
        def run(self):
            print("PySuper run")
            print("1+2+3 = ", self.call([1,2,3]))
            return True

    su = PySuper()
    su.call = caller
    print(su.run())
