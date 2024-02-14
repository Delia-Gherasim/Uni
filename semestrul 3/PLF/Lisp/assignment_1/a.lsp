(in-package :common-lisp)

;Write a function to return the n-th element of a list, or NIL if such an element does not exist
(defun a (n L)
  (cond
    ((null L) nil)
    ((= n 1) (format t "Element is ~a~%"  (car L)))
    (t (a (- n 1) (cdr L)))
  )
)

(a 4 '(A B C D))
;(a 2 '(A B C D E F G H I J K L M))