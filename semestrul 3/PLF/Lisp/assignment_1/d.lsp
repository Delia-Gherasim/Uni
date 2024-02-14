(in-package :common-lisp)

;Write a function to transform a linear list into a set.
(defun d (L)
  (cond
    ((null L) nil)
    ((member (car L) (cdr L) :test #'equal) (d (cdr L)))
    (t (cons (car L) (d (cdr L))))))

(setq result (d '(A A B C D A E)))
(print result)