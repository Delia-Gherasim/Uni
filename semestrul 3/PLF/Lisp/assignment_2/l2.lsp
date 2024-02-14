(defun parcurg_st (arb nv nm)
  (cond
   ((null arb) nil)
   ((= nv (+ 1 nm)) nil)
   (t (cons (car arb)
            (cons (cadr arb)
                  (parcurg_st (cddr arb) (+ 1 nv) (+ (cadr arb) nm)))))))

(defun stang (arb)
  (parcurg_st (cddr arb) 0 0))

(defun parcurg_drept (arb nv nm)
  (cond
   ((null arb) nil)
   ((= nv (+ 1 nm)) (cddr arb))
   (t (parcurg_drept (cddr arb) (+ 1 nv) (+ (cadr arb) nm)))))

(defun drept (arb)
  (parcurg_drept (cddr arb) 0 0))

(defun ex1 (l e)
  (cond
   ((null l) nil)
   ((= (car (cdr l)) 0) nil)
   ((eql (car l) e) (list e))
   (t (let ((left (stang l))
           (right (drept l)))
      (if (null left)
          (if (null right)
              nil
              (cons (car l) (ex1 right e)))
        (cons (car l) (ex1 left e)))))))

(setq tree '(A 2 B 0 C 2 D 0 E 0))
(print (ex1 tree 'D)) 


;(load "C:/Facultation/sem3/programare logica/lab/lisp/l2.lsp")