;1. Write a function to check if an atom is member of a list (the list is non-liniar)
(defun myOr (lst)
  (cond
    ((null lst) nil)
    ((eql (car lst) t) t)
    (t (myOr (cdr lst)))))

(defun ex1 (e lst)
  (cond 
    ((eql lst e) t)
    ((atom lst) nil)
    (t (myOr (mapcar #'(lambda (x) (ex1 e x)) lst)))))


(print (ex1 'x '(A B C D E (Q (T)))))

              

