;a) Write a function to return the product of two vectors.
(defun ex2a (l1 l2)
  (cond
    ((or (null l1) (null l2)) nil)
    ((not (numberp (car l1))) nil)
    ((not (numberp (car l2))) nil)
    (t (cons (* (car l1) (car l2))
             (ex2a (cdr l1) (cdr l2))))))
;(print(ex2a '(1 2 3) '(2 3 4)))

;b) Write a function to return the depth of a list. Example: the depth of a linear list is 1.
(defun ex2b (lst)
    (cond
        ((null lst) 0)
        ((atom lst) 0)
        ((listp lst)(1+ (apply #'max (mapcar #'ex2b lst))))
     )
)       
;(print(ex2b '(a b ( c d( e))) ))

;c) Write a function to sort a linear list without keeping the double values.
(defun sort1 (lst)
  (cond
    ((null lst) nil)
    ((null (cdr lst)) lst)
    ((< (car lst) (cadr lst)) (cons (car lst) (sort1 (cdr lst))))
    ((= (car lst) (cadr lst)) (sort1 (cdr lst)))
    (t (sort1 (cons (cadr lst) (cons (car lst) (cddr lst)))))
  )
)
(defun sort_fnct (lst n)
  (cond
    ((= n 0) lst)
    (t (sort_fnct (sort1 lst) (- n 1)))
  )
)
(defun remove_dupl (lst)
  (cond
    ((null lst) nil)
    ((null (cdr lst)) lst)
    ((= (car lst) (cadr lst)) (remove_dupl (cdr lst)))
    (t (cons (car lst) (remove_dupl (cdr lst))))
  )
)
(defun ex2c (lst n)
  (cond
    ((null lst) nil)
    ((= n 0) nil)
    (t (remove_dupl (sort_fnct lst n)))
  )
)
;(print (ex2c '(3 2 5 1 4 2 3 3) 8))

;d) Write a function to return the intersection of two sets.
(defun ex2d(l1 l2)
    (cond 
        ((or (null l1) (null l2)) nil)
        ((member (car l1) l2)(cons(car l1)(intersection (cdr l1)(cdr l2))))
        (t(intersection(cdr l1) l2))))
;(print(ex2d '( a b c d e f) '( d e f g h)))

;a) Write a function that inserts in a linear list a given atom A after the 2nd, 4th, 6th, ... element.
(defun ex3a(lst n a)
    (cond
        ((null lst) nil)
        ((null (cdr lst))(= 0 (mod n 2))(apply #' append (list(car lst)) (list a)))
        ((null (cdr lst))(= 1 (mod n 2))(list (car lst)))
        ((= 0 (mod n 2))(apply #' append (list(car lst)) (list a) (list(ex3a (cdr lst) (1+ n) a))))
        (t(apply #' append (list(car lst)) (list(ex3a (cdr lst) (1+ n) a))))
     )
)
;(print (ex3a '(a b c d e f) 1 '2))

;b) Write a function to get from a given list the list of all atoms, on any level, but reverse order. 
(defun ex3b (lst)
  (cond 
    ((null lst) nil)
    ((atom (car lst)) (append (ex3b (cdr lst))(list (car lst))))
  ;  ((listp (car lst)) (reverse (apply #'append (ex3b (car lst)) (ex3b (cdr lst)))))
    (t (append (ex3b(cdr lst))(ex3b(car lst))))
  )
)
;(print (ex3b '(((A B) C) (D E))))

;c) Write a function that returns the greatest common divisor of all numbers in a nonlinear list.
(defun cmmdc (a b)
  (cond 
    ((= a b) a)
    ((< a b) (cmmdc a (- b a)))
    ((> a b) (cmmdc (- a b) b))
  )
)

(defun getNr (lst)
  (cond
    ((null lst) nil)
    ((atom (car lst))(numberp (car lst))(append 
         (list (car lst))
         (getNr (cdr lst))))
    (t (append (getNr (car lst)) (getNr (cdr lst))))
  )
)

(defun aux (lst)
  (cond
    ((null lst) nil)
    ((and (numberp (car lst)) (numberp (cadr lst)))
     (cons (cmmdc (car lst) (cadr lst)) (aux (cddr lst))))
    (t (aux (cddr lst)))
  )
)

(defun ex3c (lst)
  (cond 
    ((null lst) nil)
    (t (aux (getNr lst)))
  )
)

;(print (ex3c '(1 (a 3 (5 c) 7 11))))

;d) Write a function that determines the number of occurrences of a given atom in a nonlinear list.
(defun ex3d(lst a)
    (cond
        ((null lst) 0)
        ((eql a (car lst))(1+ (ex3d (cdr lst) a)))
        ((atom (car lst))(ex3d (cdr lst) a))
        ((listp (car lst)) (+ (ex3d (cdr lst) a) (ex3d(car lst)a)) )  ))
;(print(ex3d '(a b c d( e a ( a g( a)))) 'a))




;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;    L3 MAP  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



;2. Write a function that returns the sum of numeric atoms in a list, at any level.
(defun ex2(lst)
    (cond 
        ((null lst) 0)
        ((numberp lst) lst)
        ((atom lst) 0)
        (t(apply #'+(mapcar #'(lambda (l)(ex2 l)) lst)))
     )
)
;(print (ex2 '(a 2 b ( 3) d((1)))))

;3. Define a function to tests the membership of a node in a n-tree represented as (root list_of_nodes_subtree1 ... list_of_nodes_subtreen) 
(defun myOr1 (lst)
  (cond
    ((null lst) nil)
    ((eql (car lst) t) t)
    (t (myOr (cdr lst)))))

(defun ex3(lst e)
    (cond 
        ((eql e lst) t)
        ((atom lst) nil)
        (t(myOr1 (mapcar #'(lambda(l)(ex3 l e)) lst)))
    )
)
;(print (ex3 '(s (a (b (c)) (d) (E (f)))) 'b))

;5. Write a function that computes the sum of even numbers and the decrease the sum of odd numbers, at any level of a list.
(defun ex5(lst)
    (cond 
        ((null lst) 0)
        ((numberp lst)(= (mod lst 2) 0) lst)
        ((numberp lst)(= (mod lst 2) 1) (- lst))    ;nu scade bn nuj
        ((atom lst) 0)
        (t(apply #'+(mapcar #' (lambda (l)(ex5 l))lst)))))
;(print(ex5 '( 1 2 3 5 (4 (10)))))

;6. Write a function that returns the maximum of numeric atoms in a list, at any level.
(defun nr(lst)
    (cond  
        ((null lst) nil)
        ((numberp lst)(list lst))
        ((atom lst)nil)
        (t (apply #'append (mapcar #'(lambda (l) (nr l)) lst)))
    )
)
(defun ex6(lst)
    (apply #'max(nr lst)))
;(print(ex6 '(1 (a 3 (5 c) 7 11))))

;7. Write a function that substitutes an element E with all elements of a list L1 at all levels of a given list L.
(defun ex7(lst e l1)
    (cond
        ((null lst) nil)
        ((atom lst)(eql lst e) (subst l1 e lst))
        (t(mapcar #'(lambda (l)(ex7 l e l1))lst))))
(defun ex7v2(lst e l1)
    (subst l1 e lst))
;(print(ex7 '(a b(c d( e f))) 'd '(22222 2)))

;8. Write a function to determine the number of nodes on the level k from a n-tree represented as follows: (root list_nodes_subtree1 ... list_nodes_subtreen) 
(defun count-nodes-at-level (tree level)
  (if (zerop level)
      1
      (apply #'+ (mapcar #'(lambda (subtree) 
                              (if (listp subtree)
                                  (count-nodes-at-level subtree (1- level))
                                  0))
                          tree))))
;(print (count-nodes-at-level '(a (b (c)) (d) (e (f))) 1))



(defun problem-2 (n ps)
  (cond 
        ((null ps) 0)
        ((funcall (car ps) n) (1+ (problem-2 n (cdr ps))))
        (T (problem-2 n (cdr ps)))
   )
)
               
(print (problem-2 2 (list (lambda (x) (< 1 x)) (lambda (x) (= 2 x)) (lambda (x) (< x 5)))))

(defun problem-3 (hash_list rotation)
  (mapcar 
    (lambda (char_from_list) (code-char (- (char-code char_from_list) rotation)))   hash_list))

(print (problem-3 '(#\C #\F #\A) 2))
(print (problem-3 '(#\C #\F #\K) 2))














