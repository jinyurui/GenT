Re struct text
================
.. toctree::
   :maxdepth:  3

   rstShow

Normal
----------------
.. code::

    this is `italic`
    this is **bold**

Title
----------------
.. code::

    1
    ===============

    1.1
    ---------------

    1.1.1
    ~~~~~~~~~~~~~~~~

Block
-----------------
.. code::

    one

    two, show block
    ::

        two.2
        two.2.3

    three

List
----------------
.. code::

    - A
    - B

        - B-1
        - B-2

    - C

Table
-----------------
.. code::

    
    +----------------------+-------------------------------+
    |        key           |           desc                |
    +======================+===============================+
    | PROJECT_NAME         |     GenT V1.0                 |
    +----------------------+-------------------------------+
    | PROJECT_LOGO         |     log.png                   |
    +----------------------+-------------------------------+


Code
-----------------
.. Code::

    .. code::

        std::cout << "hello" << std::endl;

Note
-----------------
.. code::

    .. note::

        info: helo ereryone!

Image
-----------------
.. code::

    .. image:: $(imagePath)/image.png
       :alt: hello

Link
------------------
.. code::

    path: `path <https://www.baidu.com//>`_

    `Github <https://github.com>`_







