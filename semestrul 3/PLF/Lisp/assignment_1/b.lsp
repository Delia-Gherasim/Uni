(in-package :common-lisp)
;Write a function to check whether an atom E is a member of a list which is not necessarily linear.
(defun b (e L)
  (cond
    ((null L) nil)
    ((eql e (car L)))
    (t (b e (cdr L)))
  )
)

(setq result (b 'X '(A B C D E)))
(print result)
(setq result (b 'B '(A B C D E)))
(print result)