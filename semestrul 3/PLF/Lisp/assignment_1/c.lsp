(in-package :common-lisp)
;Write a function to determine the list of all sublists of a given list, on any level.
(defun c (L)
  (cond
    ((null L) nil)
    ((listp (car L))
    (append (list (car L)) (c (car L)) (c (cdr L))))
    (t (c (cdr L)))
      
  )
)

(c '(((A) B) ((1)) C (D E)))
(setq result (c '(((A) B) ((1)) C (D E))))
(print result)
