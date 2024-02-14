(defun F(L1 L2)
    (lambda (f1)
        (append (f1)
            (cond 
                ((null l1)(cdr l2))
                (t(list f1 (car l2))))))
      (f(car l1) l2))
(defun g(l)
    (mapcon #'list l))
;(print(apply #' append (mapcon #'g '(1 2))))

(defun s3(l)
    (cond
        ((and(numberp l)(= 0 (mod l 3)))nil)
        ((atom l) (list l))
        (t(list(apply #' append (mapcar #'s3 l))))
        ))
;(print (s3 '(1 ( 2 a (3 a))((6)))))
(defun f(l)
    (cond
        ((atom l) -1)
        ((lambda (l1)
            (cond
                ((> l1 0)(+ (car l) l1)  (f(cdr l1)))))f(car l))
          
         (t(f(cdr l)))))