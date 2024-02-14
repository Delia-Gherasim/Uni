;1. For a given tree of type (1) return the path from the root node to a certain given node X
(defun find_left (tree nodes edges)
  (cond
   	((null tree) nil)
    ((= nodes (+ 1 edges)) nil)
    (t (cons (car tree) 
             (cons (cadr tree) 
                   (find_left (cddr tree) (+ 1 nodes) (+ (cadr tree) edges)))))))

(defun left (tree)
  (find_left (cddr tree) 0 0))

(defun find_right (tree nodes edges)
  (cond
   	((null tree) nil)
    ((= nodes (+ 1 edges)) tree)
    (t (find_right (cddr tree) (+ 1 nodes) (+ (cadr tree) edges)))))

(defun right (tree)
  (find_right (cddr tree) 0 0))

(defun ex1 (arb e)
  (cond
   ((null arb) nil)
   ((eql (car arb) e) (list e))
   ((= (cadr arb) 0) nil)
   (t (append (list (car arb))
              (funcall
               (lambda (s d)
                 (cond
                  ((null d) (cons (car arb) (ex1 s e)))
                  ((null s) (cons (car arb) (ex1 d e)))))
               (left arb)
               (right arb))))))


(setq tree '(A 2 B 0 C 2 D 0 E 0))
(print(stang tree))
(print(drept tree))
(print (ex1 '(A 2 B 0 C 2 D 0 E 0) 'C)) 


